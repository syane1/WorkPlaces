'''Run human tests of Idle's window, dialog, and popup widgets.

run(*tests)
Create a master Tk window.  Within that, run each callable in tests
after finding the matching test spec in this file.  If tests is empty,
run an htest for each spec dict in this file after finding the matching
callable in the module named in the spec.  Close the window to skip or
end the test.

In a tested module, let X be a global name bound to a callable (class
or function) whose .__name__ attrubute is also X (the usual situation).
The first parameter of X must be 'parent'.  When called, the parent
argument will be the root window.  X must create a child Toplevel
window (or subclass thereof).  The Toplevel may be a test widget or
dialog, in which case the callable is the corresonding class.  Or the
Toplevel may contain the widget to be tested or set up a context in
which a test widget is invoked.  In this latter case, the callable is a
wrapper function that sets up the Toplevel and other objects.  Wrapper
function names, such as _editor_window', should start with '_'.


End the module with

if __name__ == '__main__':
    <unittest, if there is one>
    from idlelib.idle_test.htest import run
    run(X)

To have wrapper functions and test invocation code ignored by coveragepy
reports, put '# htest #' on the def statement header line.

def _wrapper(parent):  # htest #

Also make sure that the 'if __name__' line matches the above.  Then have
make sure that .coveragerc includes the following.

[report]
exclude_lines =
    .*# htest #
    if __name__ == .__main__.:

(The "." instead of "'" is intentional and necessary.)


To run any X, this file must contain a matching instance of the
following template, with X.__name__ prepended to '_spec'.
When all tests are run, the prefix is use to get X.

_spec = {
    'file': '',
    'kwds': {'title': ''},
    'msg': ""
    }

file (no .py): run() imports file.py.
kwds: augmented with {'parent':root} and passed to X as **kwds.
title: an example kwd; some widgets need this, delete if not.
msg: master window hints about testing the widget.


Modules and classes not being tested at the moment:
PyShell.PyShellEditorWindow
Debugger.Debugger
AutoCompleteWindow.AutoCompleteWindow
OutputWindow.OutputWindow (indirectly being tested with grep test)
'''

from importlib import import_module
from idlelib.macosxSupport import _initializeTkVariantTests
import Tkinter as tk

AboutDialog_spec = {
    'file': 'aboutDialog',
    'kwds': {'title': 'aboutDialog test',
             '_htest': True,
             },
    'msg': "Test every button. Ensure Python, TK and IDLE versions "
           "are correctly displayed.\n [Close] to exit.",
    }

_calltip_window_spec = {
    'file': 'CallTipWindow',
    'kwds': {},
    'msg': "Typing '(' should display a calltip.\n"
           "Typing ') should hide the calltip.\n"
    }

_class_browser_spec = {
    'file': 'ClassBrowser',
    'kwds': {},
    'msg': "Inspect names of module, class(with superclass if "
           "applicable), methods and functions.\nToggle nested items.\n"
           "Double clicking on items prints a traceback for an exception "
           "that is ignored."
    }
ConfigExtensionsDialog_spec = {
    'file': 'configDialog',
    'kwds': {'title': 'Test Extension Configuration',
             '_htest': True,},
    'msg': "IDLE extensions dialog.\n"
           "\n[Ok] to close the dialog.[Apply] to apply the settings and "
           "and [Cancel] to revert all changes.\nRe-run the test to ensure "
           "changes made have persisted."
    }

_color_delegator_spec = {
    'file': 'ColorDelegator',
    'kwds': {},
    'msg': "The text is sample Python code.\n"
           "Ensure components like comments, keywords, builtins,\n"
           "string, definitions, and break are correctly colored.\n"
           "The default color scheme is in idlelib/config-highlight.def"
    }

ConfigDialog_spec = {
    'file': 'configDialog',
    'kwds': {'title': 'ConfigDialogTest',
             '_htest': True,},
    'msg': "IDLE preferences dialog.\n"
           "In the 'Fonts/Tabs' tab, changing font face, should update the "
           "font face of the text in the area below it.\nIn the "
           "'Highlighting' tab, try different color schemes. Clicking "
           "items in the sample program should update the choices above it."
           "\nIn the 'Keys' and 'General' tab, test settings of interest."
           "\n[Ok] to close the dialog.[Apply] to apply the settings and "
           "and [Cancel] to revert all changes.\nRe-run the test to ensure "
           "changes made have persisted."
    }

# TODO Improve message
_dyn_option_menu_spec = {
    'file': 'dynOptionMenuWidget',
    'kwds': {},
    'msg': "Select one of the many options in the 'old option set'.\n"
           "Click the button to change the option set.\n"
           "Select one of the many options in the 'new option set'."
    }

# TODO edit wrapper
_editor_window_spec = {
   'file': 'EditorWindow',
    'kwds': {},
    'msg': "Test editor functions of interest.\n"
           "Best to close editor first."
    }

GetCfgSectionNameDialog_spec = {
    'file': 'configSectionNameDialog',
    'kwds': {'title':'Get Name',
             'message':'Enter something',
             'used_names': {'abc'},
             '_htest': True},
    'msg': "After the text entered with [Ok] is stripped, <nothing>, "
           "'abc', or more that 30 chars are errors.\n"
           "Close 'Get Name' with a valid entry (printed to Shell), "
           "[Cancel], or [X]",
    }

GetHelpSourceDialog_spec = {
    'file': 'configHelpSourceEdit',
    'kwds': {'title': 'Get helpsource',
             '_htest': True},
    'msg': "Enter menu item name and help file path\n "
           "<nothing> and more than 30 chars are invalid menu item names.\n"
           "<nothing>, file does not exist are invalid path items.\n"
           "Test for incomplete web address for help file path.\n"
           "A valid entry will be printed to shell with [0k].\n"
           "[Cancel] will print None to shell",
    }

# Update once issue21519 is resolved.
GetKeysDialog_spec = {
    'file': 'keybindingDialog',
    'kwds': {'title': 'Test keybindings',
             'action': 'find-again',
             'currentKeySequences': [''] ,
             '_htest': True,
             },
    'msg': "Test for different key modifier sequences.\n"
           "<nothing> is invalid.\n"
           "No modifier key is invalid.\n"
           "Shift key with [a-z],[0-9], function key, move key, tab, space"
           "is invalid.\nNo validitity checking if advanced key binding "
           "entry is used."
    }

_grep_dialog_spec = {
    'file': 'GrepDialog',
    'kwds': {},
    'msg': "Click the 'Show GrepDialog' button.\n"
           "Test the various 'Find-in-files' functions.\n"
           "The results should be displayed in a new '*Output*' window.\n"
           "'Right-click'->'Goto file/line' anywhere in the search results "
           "should open that file \nin a new EditorWindow."
    }

_help_dialog_spec = {
    'file': 'EditorWindow',
    'kwds': {},
    'msg': "If the help text displays, this works.\n"
           "Text is selectable. Window is scrollable."
    }

_io_binding_spec = {
    'file': 'IOBinding',
    'kwds': {},
    'msg': "Test the following bindings\n"
           "<Control-o> to display open window from file dialog.\n"
           "<Control-s> to save the file\n"
    }

_multi_call_spec = {
    'file': 'MultiCall',
    'kwds': {},
    'msg': "The following actions should trigger a print to console or IDLE"
           " Shell.\nEntering and leaving the text area, key entry, "
           "<Control-Key>,\n<Alt-Key-a>, <Control-Key-a>, "
           "<Alt-Control-Key-a>, \n<Control-Button-1>, <Alt-Button-1> and "
           "focusing out of the window\nare sequences to be tested."
    }

_multistatus_bar_spec = {
    'file': 'MultiStatusBar',
    'kwds': {},
    'msg': "Ensure presence of multi-status bar below text area.\n"
           "Click 'Update Status' to change the multi-status text"
    }

_object_browser_spec = {
    'file': 'ObjectBrowser',
    'kwds': {},
    'msg': "Double click on items upto the lowest level.\n"
           "Attributes of the objects and related information "
           "will be displayed side-by-side at each level."
    }

_path_browser_spec = {
    'file': 'PathBrowser',
    'kwds': {},
    'msg': "Test for correct display of all paths in sys.path.\n"
           "Toggle nested items upto the lowest level.\n"
           "Double clicking on an item prints a traceback\n"
           "for an exception that is ignored."
    }

_percolator_spec = {
    'file': 'Percolator',
    'kwds': {},
    'msg': "There are two tracers which can be toggled using a checkbox.\n"
           "Toggling a tracer 'on' by checking it should print tracer"
           "output to the console or to the IDLE shell.\n"
           "If both the tracers are 'on', the output from the tracer which "
           "was switched 'on' later, should be printed first\n"
           "Test for actions like text entry, and removal."
    }

_replace_dialog_spec = {
    'file': 'ReplaceDialog',
    'kwds': {},
    'msg': "Click the 'Replace' button.\n"
           "Test various replace options in the 'Replace dialog'.\n"
           "Click [Close] or [X] to close the 'Replace Dialog'."
    }

_search_dialog_spec = {
    'file': 'SearchDialog',
    'kwds': {},
    'msg': "Click the 'Search' button.\n"
           "Test various search options in the 'Search dialog'.\n"
           "Click [Close] or [X] to close the 'Search Dialog'."
    }

_scrolled_list_spec = {
    'file': 'ScrolledList',
    'kwds': {},
    'msg': "You should see a scrollable list of items\n"
           "Selecting (clicking) or double clicking an item "
           "prints the name to the console or Idle shell.\n"
           "Right clicking an item will display a popup."
    }

_stack_viewer_spec = {
    'file': 'StackViewer',
    'kwds': {},
    'msg': "A stacktrace for a NameError exception.\n"
           "Expand 'idlelib ...' and '<locals>'.\n"
           "Check that exc_value, exc_tb, and exc_type are correct.\n"
    }

_tabbed_pages_spec = {
    'file': 'tabbedpages',
    'kwds': {},
    'msg': "Toggle between the two tabs 'foo' and 'bar'\n"
           "Add a tab by entering a suitable name for it.\n"
           "Remove an existing tab by entering its name.\n"
           "Remove all existing tabs.\n"
           "<nothing> is an invalid add page and remove page name.\n"
    }

TextViewer_spec = {
    'file': 'textView',
    'kwds': {'title': 'Test textView',
             'text':'The quick brown fox jumps over the lazy dog.\n'*35,
             '_htest': True},
    'msg': "Test for read-only property of text.\n"
           "Text is selectable. Window is scrollable.",
     }

_tooltip_spec = {
    'file': 'ToolTip',
    'kwds': {},
    'msg': "Place mouse cursor over both the buttons\n"
           "A tooltip should appear with some text."
    }

_tree_widget_spec = {
    'file': 'TreeWidget',
    'kwds': {},
    'msg': "The canvas is scrollable.\n"
           "Click on folders upto to the lowest level."
    }

_undo_delegator_spec = {
    'file': 'UndoDelegator',
    'kwds': {},
    'msg': "Click [Undo] to undo any action.\n"
           "Click [Redo] to redo any action.\n"
           "Click [Dump] to dump the current state "
           "by printing to the console or the IDLE shell.\n"
    }

_widget_redirector_spec = {
    'file': 'WidgetRedirector',
    'kwds': {},
    'msg': "Every text insert should be printed to the console."
           "or the IDLE shell."
    }

def run(*tests):
    root = tk.Tk()
    root.title('IDLE htest')
    root.resizable(0, 0)
    _initializeTkVariantTests(root)

    # a scrollable Label like constant width text widget.
    frameLabel = tk.Frame(root, padx=10)
    frameLabel.pack()
    text = tk.Text(frameLabel, wrap='word')
    text.configure(bg=root.cget('bg'), relief='flat', height=4, width=70)
    scrollbar = tk.Scrollbar(frameLabel, command=text.yview)
    text.config(yscrollcommand=scrollbar.set)
    scrollbar.pack(side='right', fill='y', expand=False)
    text.pack(side='left', fill='both', expand=True)

    test_list = [] # List of tuples of the form (spec, callable widget)
    if tests:
        for test in tests:
            test_spec = globals()[test.__name__ + '_spec']
            test_spec['name'] = test.__name__
            test_list.append((test_spec,  test))
    else:
        for k, d in globals().items():
            if k.endswith('_spec'):
                test_name = k[:-5]
                test_spec = d
                test_spec['name'] = test_name
                mod = import_module('idlelib.' + test_spec['file'])
                test = getattr(mod, test_name)
                test_list.append((test_spec, test))

    test_name = [tk.StringVar('')]
    callable_object = [None]
    test_kwds = [None]


    def next():
        if len(test_list) == 1:
            next_button.pack_forget()
        test_spec, callable_object[0] = test_list.pop()
        test_kwds[0] = test_spec['kwds']
        test_kwds[0]['parent'] = root
        test_name[0].set('Test ' + test_spec['name'])

        text.configure(state='normal') # enable text editing
        text.delete('1.0','end')
        text.insert("1.0",test_spec['msg'])
        text.configure(state='disabled') # preserve read-only property

    def run_test():
        widget = callable_object[0](**test_kwds[0])
        try:
            print(widget.result)
        except AttributeError:
            pass

    button = tk.Button(root, textvariable=test_name[0], command=run_test)
    button.pack()
    next_button = tk.Button(root, text="Next", command=next)
    next_button.pack()

    next()

    root.mainloop()

if __name__ == '__main__':
    run()
