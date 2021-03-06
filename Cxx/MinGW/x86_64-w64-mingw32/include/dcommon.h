/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_DCOMMON__
#define __INC_DCOMMON__

typedef enum DWRITE_MEASURING_MODE {
  DWRITE_MEASURING_MODE_NATURAL = 0,
  DWRITE_MEASURING_MODE_GDI_CLASSIC,
  DWRITE_MEASURING_MODE_GDI_NATURAL 
} DWRITE_MEASURING_MODE;

enum DWRITE_GLYPH_IMAGE_FORMATS {
    DWRITE_GLYPH_IMAGE_FORMATS_NONE      = 0x0000,
    DWRITE_GLYPH_IMAGE_FORMATS_TRUETYPE  = 0x0001,
    DWRITE_GLYPH_IMAGE_FORMATS_CFF       = 0x0002,
    DWRITE_GLYPH_IMAGE_FORMATS_COLR      = 0x0004,
    DWRITE_GLYPH_IMAGE_FORMATS_SVG       = 0x0008,
    DWRITE_GLYPH_IMAGE_FORMATS_PNG       = 0x0010,
    DWRITE_GLYPH_IMAGE_FORMATS_JPEG      = 0x0020,
    DWRITE_GLYPH_IMAGE_FORMATS_TIFF      = 0x0040,
    DWRITE_GLYPH_IMAGE_FORMATS_PREMULTIPLIED_B8G8R8A8 = 0x0080,
};

typedef POINT D2D_POINT_2L;
typedef D2D_POINT_2L D2D1_POINT_2L;

struct D2D_SIZE_U {
  UINT32 width;
  UINT32 height;
};

typedef struct D2D_SIZE_U D2D1_SIZE_U;

#endif /*#define __INC_DCOMMON__*/
