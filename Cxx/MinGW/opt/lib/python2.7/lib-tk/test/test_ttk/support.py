import unittest
import Tkinter as tkinter

class AbstractTkTest:

    @classmethod
    def setUpClass(cls):
        cls._old_support_default_root = tkinter._support_default_root
        destroy_default_root()
        tkinter.NoDefaultRoot()
        cls.root = tkinter.Tk()
        cls.wantobjects = cls.root.wantobjects()
        # De-maximize main window.
        # Some window managers can maximize new windows.
        cls.root.wm_state('normal')
        try:
            cls.root.wm_attributes('-zoomed', False)
        except tkinter.TclError:
            pass

    @classmethod
    def tearDownClass(cls):
        cls.root.update_idletasks()
        cls.root.destroy()
        cls.root = None
        tkinter._default_root = None
        tkinter._support_default_root = cls._old_support_default_root

    def setUp(self):
        self.root.deiconify()

    def tearDown(self):
        for w in self.root.winfo_children():
            w.destroy()
        self.root.withdraw()

def destroy_default_root():
    if getattr(tkinter, '_default_root', None):
        tkinter._default_root.update_idletasks()
        tkinter._default_root.destroy()
        tkinter._default_root = None

def simulate_mouse_click(widget, x, y):
    """Generate proper events to click at the x, y position (tries to act
    like an X server)."""
    widget.event_generate('<Enter>', x=0, y=0)
    widget.event_generate('<Motion>', x=x, y=y)
    widget.event_generate('<ButtonPress-1>', x=x, y=y)
    widget.event_generate('<ButtonRelease-1>', x=x, y=y)


import _tkinter
tcl_version = tuple(map(int, _tkinter.TCL_VERSION.split('.')))

def requires_tcl(*version):
    return unittest.skipUnless(tcl_version >= version,
            'requires Tcl version >= ' + '.'.join(map(str, version)))

_tk_patchlevel = None
def get_tk_patchlevel():
    global _tk_patchlevel
    if _tk_patchlevel is None:
        tcl = tkinter.Tcl()
        patchlevel = []
        for x in tcl.call('info', 'patchlevel').split('.'):
            try:
                x = int(x, 10)
            except ValueError:
                x = -1
            patchlevel.append(x)
        _tk_patchlevel = tuple(patchlevel)
    return _tk_patchlevel

units = {
    'c': 72 / 2.54,     # centimeters
    'i': 72,            # inches
    'm': 72 / 25.4,     # millimeters
    'p': 1,             # points
}

def pixels_conv(value):
    return float(value[:-1]) * units[value[-1:]]

def tcl_obj_eq(actual, expected):
    if actual == expected:
        return True
    if isinstance(actual, _tkinter.Tcl_Obj):
        if isinstance(expected, str):
            return str(actual) == expected
    if isinstance(actual, tuple):
        if isinstance(expected, tuple):
            return (len(actual) == len(expected) and
                    all(tcl_obj_eq(act, exp)
                        for act, exp in zip(actual, expected)))
    return False

def widget_eq(actual, expected):
    if actual == expected:
        return True
    if isinstance(actual, (str, tkinter.Widget)):
        if isinstance(expected, (str, tkinter.Widget)):
            return str(actual) == str(expected)
    return False
