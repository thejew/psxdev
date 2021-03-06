
#ifndef LIBPSX_GPU_H
#define LIBPSX_GPU_H

#include <stdint.h>

// 15bpp format: bbbbb---ggggg---rrrrr---
// 24bpp format: bbbbbbbbggggggggrrrrrrrr

// GPU Registers
#define GP  ((volatile unsigned*)0x1F801810)

// Send command c with parameter(s) p
#define GP0_DO(c,p)  GP[0] = (((c)<<24)|(p))
#define GP1_DO(c,p)  GP[1] = (((c)<<24)|(p))

#define GP0NOP  GP0_DO(0x00,0)

// GPUSTAT flags
#define Gp0CmdReady 0x04000000
#define Gp0DmaReady 0x10000000

void waitGpu(unsigned status);


// GP0 drawing commands
#define FlatTriOpaque               0x20
#define FlatTri                     0x22
#define FlatQuadOpaque              0x28
#define FlatQuad                    0x2A

#define TexTriOpaqueBlend           0x24
#define TexTriOpaqueRaw             0x25
#define TexTriBlend                 0x26
#define TexTriRaw                   0x27
#define TexQuadOpaqueBlend          0x24
#define TexQuadOpaqueRaw            0x25
#define TexQuadBlend                0x26
#define TexQuadRaw                  0x27

#define ShadedTriOpaque             0x30
#define ShadedTri                   0x32
#define ShadedQuadOpaque            0x38
#define ShadedQuad                  0x3A

#define ShadedTexTriOpaqueBlend     0x34
#define ShadedTexTriBlend           0x36
#define ShadedTexQuadOpaqueBlend    0x3C
#define ShadedTexQuadBlend          0x3E

#define FlatLineOpaque              0x40
#define FlatLine                    0x42
#define FlatPolyLineOpaque          0x48
#define FlatPolyLine                0x4A

#define ShadedLineOpaque            0x50
#define ShadedLine                  0x52
#define ShadedPolyLineOpaque        0x58
#define ShadedPolyLine              0x5A

#define FlatRectVarOpaque           0x60
#define FlatRectVar                 0x62
#define FlatRect1x1Opaque           0x68
#define FlatRect1x1                 0x6A
#define FlatRect8x8Opaque           0x70
#define FlatRect8x8                 0x72
#define FlatRect16x16Opaque         0x78
#define FlatRect16x16               0x7A

#define TexRectVarOpaqueBlend       0x64
#define TexRectVarOpaqueRaw         0x65
#define TexRectVarBlend             0x66
#define TexRectVarRaw               0x67
// "nonsense" instructions
//#define TexRect1x1OpaqueBlend       0x6C
//#define TexRect1x1OpaqueRaw         0x6D
//#define TexRect1x1Blend             0x6E
//#define TexRect1x1Raw               0x6F
#define TexRect8x8OpaqueBlend       0x74
#define TexRect8x8OpaqueRaw         0x75
#define TexRect8x8Blend             0x76
#define TexRect8x8Raw               0x77
#define TexRect16x16OpaqueBlend     0x7C
#define TexRect16x16OpaqueRaw       0x7D
#define TexRect16x16Blend           0x7E
#define TexRect16x16Raw             0x7F

// GP0 memory transfer commands
#define ClearCache          0x01
#define FillRectVram        0x02
#define CopyRectVramVram    0x80
#define CopyRectCpuVram     0xA0
#define CopyRectVramCpu     0xC0

// GP0 rendering attribute commands
#define DrawMode            0xE1
#define TextureWindow       0xE2
#define DrawAreaTopLeft     0xE3
#define DrawAreaBottomRight 0xE4
#define DrawOffset          0xE5
#define DrawMaskBit         0xE6

// GP1 display commands
#define ResetGpu            0x00
#define ResetCommandBuffer  0x01
#define AcknowledgeGpuIrq   0x02
#define EnableDisplay       0x03
#define DmaDirection        0x04
#define DisplayArea         0x05
#define DisplayRangeH       0x06
#define DisplayRangeV       0x07
#define DisplayMode         0x08
#define TextureDisable      0x09
#define GetGpuInfo          0x10

#define DMODE_HRES_256      0x00
#define DMODE_HRES_320      0x01
#define DMODE_HRES_512      0x02
#define DMODE_HRES_640      0x03
#define DMODE_VRES_240      0x00
#define DMODE_VRES_480      0x04

void setDisplayMode(unsigned mode);

void setDisplayOrigin(uint16_t x, uint16_t y);

#endif

