
@{{BLOCK(man)

@=======================================================================
@
@	man, 96x128@8, 
@	+ palette 256 entries, not compressed
@	+ 192 tiles Metatiled by 4x4 not compressed
@	Total size: 512 + 12288 = 12800
@
@	Time-stamp: 2011-11-30, 19:46:45
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.9
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global manTiles		@ 12288 unsigned chars
manTiles:
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0F0F0101
	.word 0x01010101,0x0F010101,0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x0D170101
	.word 0x01010101,0x01010101,0x01010101,0x0D0D1717,0x170F0F01,0x060D0D0D,0x06060D0F,0x0D0D170D
	.word 0x0D06060D,0x060D0D17,0x0D06170F,0x0D0D170D,0x170D0D0D,0x17170D0D,0x17171711,0x0F0D060D
	.word 0x01010101,0x01010101,0x170D0D0D,0x01010F17,0x06060606,0x17170D0D,0x06060606,0x0D0D1111
	.word 0x06060606,0x06111106,0x06060D0D,0x11111111,0x170D0D0D,0x06110D0D,0x0617170F,0x170D0D17
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010117,0x01010101
	.word 0x0101170D,0x01010101,0x01011706,0x01010101,0x010F0D06,0x01010101,0x01170D0D,0x01010101

	.word 0x01010101,0x11080101,0x01010101,0x17080101,0x01010101,0x0D170801,0x01010101,0x06170801
	.word 0x01010101,0x0D060801,0x01010101,0x170D0D0F,0x01010101,0x0017170F,0x01010101,0x1717010F
	.word 0x0D06060D,0x11060D17,0x170D0D0F,0x0D060D0F,0x170F0F0D,0x0F060D17,0x0F0D170D,0x0D061716
	.word 0x0E061706,0x060F0000,0x1F0E0F06,0x0F001F16,0x1D001706,0x0B0B000A,0x0308000B,0x10140000
	.word 0x0D060611,0x0D0D170F,0x0F170D06,0x060D1717,0x170F1717,0x0D17170D,0x0D170F0F,0x0F170D06
	.word 0x000F0F0D,0x060D0E00,0x1F000F06,0x060E1F16,0x0A0B160F,0x06171D00,0x00140F0B,0x0B000300
	.word 0x17171717,0x01010101,0x08060D06,0x01010101,0x0D170606,0x01010101,0x0F060D0D,0x01010101
	.word 0x0F0D170F,0x01010101,0x0D0F0F17,0x0101010F,0x0F000B00,0x0101010F,0x01170008,0x0101010F

	.word 0x01010101,0x0F010101,0x01010101,0x17010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x00010101,0x01010101,0x00010101,0x01010101,0x19000101
	.word 0x0A0E0016,0x10101D1D,0x0A160D17,0x10101B1B,0x161F0D08,0x1010100B,0x1F1A0001,0x0B0B0416
	.word 0x131A1600,0x16161607,0x21160B16,0x1A1C1813,0x1A161416,0x181A0C21,0x08191902,0x1A21210C
	.word 0x1D101010,0x16000A1D,0x1B101010,0x0D160A1B,0x10101010,0x0D1F160B,0x040B0B0B,0x00071F16
	.word 0x16161616,0x161A2107,0x181C1A0B,0x161A0C13,0x1A1A1800,0x0B0C1A0C,0x0C211A13,0x1608080C
	.word 0x01011708,0x01010101,0x01011708,0x01010101,0x01010108,0x01010101,0x01010101,0x01010101
	.word 0x01010100,0x01010101,0x01010005,0x01010101,0x01010016,0x01010101,0x0100190B,0x01010101

	.word 0x01010101,0x19000101,0x01010101,0x19000101,0x01010101,0x00010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x00021E1E,0x21210C1A,0x05191402,0x1A0C1A12,0x22001919,0x22121222,0x1A1F0000,0x0522221A
	.word 0x00010101,0x0C1A1A1F,0x01010101,0x080E1F08,0x01010101,0x00080801,0x01010101,0x01010101
	.word 0x0C0C2121,0x1908001A,0x1A0C1A1A,0x19080512,0x12151222,0x1F082222,0x15120508,0x00051212
	.word 0x05210C08,0x01000515,0x1F0E0E00,0x01010100,0x04040400,0x01010100,0x001F0E00,0x01010101
	.word 0x01000219,0x01010101,0x01001602,0x01010101,0x01010000,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0F0F0101,0x01010101,0x0F010101
	.word 0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x0D170101,0x01010101,0x11080101
	.word 0x01010101,0x0D0D1717,0x170F0F01,0x060D0D0D,0x06060D0F,0x0D0D170D,0x0D06060D,0x060D0D17
	.word 0x0D06170F,0x0D0D170D,0x170D0D0D,0x17170D0D,0x17171711,0x0F0D060D,0x0D06060D,0x11060D17
	.word 0x170D0D0D,0x01010F17,0x06060606,0x17170D0D,0x06060606,0x0D0D1111,0x06060606,0x06111106
	.word 0x06060D0D,0x11111111,0x170D0D0D,0x06110D0D,0x0617170F,0x170D0D17,0x0D060611,0x0D0D170F
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010117,0x01010101,0x0101170D,0x01010101
	.word 0x01011706,0x01010101,0x010F0D06,0x01010101,0x01170D0D,0x01010101,0x17171717,0x01010101

	.word 0x01010101,0x17080101,0x01010101,0x0D170801,0x01010101,0x06170801,0x01010101,0x0D060801
	.word 0x01010101,0x170D0D0F,0x01010101,0x0017170F,0x01010101,0x1717010F,0x01010101,0x0F010101
	.word 0x170D0D0F,0x0D060D0F,0x170F0F0D,0x0F060D17,0x0F0D170D,0x0D061716,0x0E061706,0x060F0000
	.word 0x1F0E0F06,0x0F001F16,0x1D001706,0x0B0B000A,0x0308000B,0x10140000,0x0A0E0016,0x10101D1D
	.word 0x0F170D06,0x060D1717,0x170F1717,0x0D17170D,0x0D170F0F,0x0F170D06,0x000F0F0D,0x060D0E00
	.word 0x1F000F06,0x060E1F16,0x0A0B160F,0x06171D00,0x00140F0B,0x0B000300,0x1D101010,0x16000A1D
	.word 0x08060D06,0x01010101,0x0D170606,0x01010101,0x0F060D0D,0x01010101,0x0F0D170F,0x01010101
	.word 0x0D0F0F17,0x0101010F,0x0F000B00,0x0101010F,0x01170008,0x0101010F,0x01011708,0x01010101

	.word 0x01010101,0x17010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x00010101,0x01010101,0x00010101,0x01010101,0x19000101,0x01010101,0x02190001
	.word 0x0A160D17,0x10101B1B,0x161F0D08,0x1010100B,0x1F1A0001,0x0B0B0416,0x131A1600,0x16161607
	.word 0x211A0B16,0x1A1C1813,0x1A211416,0x181A1A21,0x08080B14,0x1A21210C,0x00081919,0x21210C1A
	.word 0x1B101010,0x0D160A1B,0x10101010,0x0D1F160B,0x040B0B0B,0x00071F16,0x16161616,0x161A1307
	.word 0x181C1A0B,0x0B1A2113,0x1A1A1800,0x14211A21,0x21211A13,0x0B08080C,0x0C212121,0x1908001A
	.word 0x01011708,0x01010101,0x01010108,0x01010101,0x01010101,0x01010101,0x01010100,0x01010101
	.word 0x01010016,0x01010101,0x01010016,0x01010101,0x01001914,0x01010101,0x00190219,0x01010101

	.word 0x01010101,0x1E190001,0x01010101,0x02000101,0x01010101,0x00010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x0508191E,0x1A0C1A12,0x22081F0B,0x12151222,0x12050000,0x05151515,0x22050101,0x1A080522
	.word 0x05000101,0x0C210C08,0x00010101,0x080E0404,0x00010101,0x010E0E1F,0x01010101,0x01000000
	.word 0x1A0C1A1A,0x19080512,0x12151222,0x1F082222,0x15150508,0x00051215,0x05081A1A,0x01052222
	.word 0x0C210C08,0x01000508,0x040E0801,0x01010004,0x0E0E0101,0x0101001F,0x00000101,0x01010100
	.word 0x00191E1E,0x01010101,0x0100020B,0x01010101,0x01010000,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0F0F0101
	.word 0x01010101,0x0F010101,0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x0D170101
	.word 0x01010101,0x01010101,0x01010101,0x0D0D1717,0x170F0F01,0x060D0D0D,0x06060D0F,0x0D0D170D
	.word 0x0D06060D,0x060D0D17,0x0D06170F,0x0D0D170D,0x170D0D0D,0x17170D0D,0x17171711,0x0F0D060D
	.word 0x01010101,0x01010101,0x170D0D0D,0x01010F17,0x06060606,0x17170D0D,0x06060606,0x0D0D1111
	.word 0x06060606,0x06111106,0x06060D0D,0x11111111,0x170D0D0D,0x06110D0D,0x0617170F,0x170D0D17
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010117,0x01010101
	.word 0x0101170D,0x01010101,0x01011706,0x01010101,0x010F0D06,0x01010101,0x01170D0D,0x01010101

	.word 0x01010101,0x11080101,0x01010101,0x17080101,0x01010101,0x0D170801,0x01010101,0x06170801
	.word 0x01010101,0x0D060801,0x01010101,0x170D0D0F,0x01010101,0x0017170F,0x01010101,0x1717010F
	.word 0x0D06060D,0x11060D17,0x170D0D0F,0x0D060D0F,0x170F0F0D,0x0F060D17,0x0F0D170D,0x0D061716
	.word 0x0E061706,0x060F0000,0x1F0E0F06,0x0F001F16,0x1D001706,0x0B0B000A,0x0308000B,0x10140000
	.word 0x0D060611,0x0D0D170F,0x0F170D06,0x060D1717,0x170F1717,0x0D17170D,0x0D170F0F,0x0F170D06
	.word 0x000F0F0D,0x060D0E00,0x1F000F06,0x060E1F16,0x0A0B160F,0x06171D00,0x00140F0B,0x0B000300
	.word 0x17171717,0x01010101,0x08060D06,0x01010101,0x0D170606,0x01010101,0x0F060D0D,0x01010101
	.word 0x0F0D170F,0x01010101,0x0D0F0F17,0x0101010F,0x0F000B00,0x0101010F,0x01170008,0x0101010F

	.word 0x01010101,0x0F010101,0x01010101,0x17010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x00010101,0x01010101,0x00010101,0x01010101,0x19000101
	.word 0x0A0E0016,0x10101D1D,0x0A160D17,0x10101B1B,0x161F0D08,0x1010100B,0x1F070001,0x0B0B0416
	.word 0x211A1600,0x16161607,0x0C1A1605,0x1A1C1813,0x1A0C0B16,0x181A1A0C,0x0808160B,0x1A210C0C
	.word 0x1D101010,0x16000A1D,0x1B101010,0x0D160A1B,0x10101010,0x0D1F160B,0x040B0B0B,0x001A1F16
	.word 0x16161616,0x161A1307,0x181C1A0B,0x0B162113,0x0C1A1800,0x14161A21,0x21211A13,0x1919080C
	.word 0x01011708,0x01010101,0x01011708,0x01010101,0x01010108,0x01010101,0x01010101,0x01010101
	.word 0x01010100,0x01010101,0x01010016,0x01010101,0x01010016,0x01010101,0x01001902,0x01010101

	.word 0x01010101,0x02000101,0x01010101,0x16000101,0x01010101,0x00010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x00081919,0x210C0C1A,0x05081902,0x1A0C1A12,0x22081F00,0x12151222,0x12050001,0x05121512
	.word 0x05000101,0x0C210515,0x01010101,0x0E0E1F00,0x01010101,0x04040400,0x01010101,0x0E1F0001
	.word 0x0C212121,0x1E02001A,0x1A0C1A1A,0x14190512,0x12122222,0x19002222,0x22220508,0x001F1A1A
	.word 0x1A1A0C08,0x0101001F,0x1F0E0800,0x01010108,0x08080000,0x01010101,0x01010100,0x01010101
	.word 0x0100191E,0x01010101,0x01001902,0x01010101,0x01010019,0x01010101,0x01010100,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01170101
	.word 0x01010101,0x170D1701,0x01010101,0x0D170D0F,0x01010101,0x0D0F0D0F,0x01010101,0x0D0D0F01
	.word 0x01010101,0x01010101,0x01010101,0x0D17170F,0x17170801,0x0606060D,0x06060D17,0x06060606
	.word 0x0D06060D,0x060D0D0D,0x0D0D0D06,0x17170D0D,0x170D0611,0x060D1717,0x06111106,0x0D060606
	.word 0x01010101,0x01010101,0x17170D0D,0x01010101,0x06110606,0x0101170D,0x11060606,0x01170D06
	.word 0x11110617,0x0F0D0611,0x060D170D,0x0D061106,0x0D0D170D,0x0D06060D,0x17060D17,0x0D060D0D
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x0101010F,0x01010101,0x01010117,0x01010101,0x01010F0D,0x01010101

	.word 0x01010101,0x17170F01,0x01010101,0x0F0D170F,0x01010101,0x0F170D0F,0x01010101,0x0F170D00
	.word 0x01010101,0x00170001,0x01010101,0x0E000101,0x01010101,0x08010101,0x01010101,0x00010101
	.word 0x060D0D17,0x170F0D06,0x0D170F0F,0x1717080D,0x000D170E,0x0D040400,0x0800160E,0x0D080816
	.word 0x0A0E0B0E,0x0F080300,0x00140B0E,0x0E080A00,0x1D14040E,0x0B0E0A1D,0x1B10040B,0x0B140A1B
	.word 0x0D060D17,0x0D0D1717,0x06061717,0x1717170D,0x0D0D170D,0x0F170606,0x17170606,0x170D0D0D
	.word 0x0D0D0D17,0x17170F17,0x0F170F0E,0x0F0F0F0F,0x0B080B0E,0x170F0F0F,0x08081408,0x0F17170F
	.word 0x01010F0D,0x01010101,0x01010F0F,0x01010101,0x01010F17,0x01010101,0x01010F0F,0x01010101
	.word 0x0F0F0D0D,0x01010101,0x01010F0F,0x01010101,0x01010F0F,0x01010101,0x01010F01,0x01010101

	.word 0x01010101,0x1F010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x1010100B,0x0B101010,0x10140B00,0x090B1010,0x0B240001,0x09040B0B,0x00000101,0x181C0909
	.word 0x01010101,0x1A131800,0x00010101,0x210C1318,0x13000101,0x21212121,0x21000101,0x1A0C2121
	.word 0x0F080908,0x0F0F170F,0x0F080808,0x010F170F,0x13181C1C,0x01010F17,0x1A1A1A13,0x01010F0F
	.word 0x16161A1A,0x01010F00,0x140B161A,0x01010100,0x260B001A,0x01010016,0x16191900,0x01010016
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x1A000101,0x191A0C0C,0x00010101,0x1F001A1A,0x22000101,0x10002222,0x12000101,0x1F121215
	.word 0x00010101,0x1F121512,0x0E000101,0x1F1A1A00,0x0E000101,0x1A000E0E,0x01010101,0x01010101
	.word 0x19190202,0x0101001A,0x1A02191E,0x01010100,0x1A1E191F,0x01010100,0x00000B0B,0x01010023
	.word 0x1F082424,0x01001F07,0x0000001A,0x01000E1F,0x0E0E001A,0x0100040E,0x04040001,0x01010E04
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01170101,0x01010101,0x170D1701
	.word 0x01010101,0x0D170D0F,0x01010101,0x0D0F0D0F,0x01010101,0x0D0D0F01,0x01010101,0x17170F01
	.word 0x01010101,0x0D17170F,0x17170801,0x0606060D,0x06060D17,0x06060606,0x0D06060D,0x060D0D0D
	.word 0x0D0D0D06,0x17170D0D,0x170D0611,0x060D1717,0x06111106,0x0D060606,0x060D0D17,0x170F0D06
	.word 0x17170D0D,0x01010101,0x06110606,0x0101170D,0x11060606,0x01170D06,0x11110617,0x0F0D0611
	.word 0x060D170D,0x0D061106,0x0D0D170D,0x0D06060D,0x17060D17,0x0D060D0D,0x0D060D17,0x0D0D1717
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x0101010F,0x01010101,0x01010117,0x01010101,0x01010F0D,0x01010101,0x01010F0D,0x01010101

	.word 0x01010101,0x0F0D170F,0x01010101,0x0F170D0F,0x01010101,0x0F170D00,0x01010101,0x00170001
	.word 0x01010101,0x0E000101,0x01010101,0x08010101,0x01010101,0x00010101,0x01010101,0x1F010101
	.word 0x0D170F0F,0x1717080D,0x000D170E,0x0D040400,0x0800160E,0x0D080816,0x0A0E0B0E,0x0F080300
	.word 0x00140B0E,0x0E080A00,0x1D14040E,0x0B0E0A1D,0x1B10040B,0x0B140A1B,0x1010100B,0x0B101010
	.word 0x06061717,0x1717170D,0x0D0D170D,0x0F170606,0x17170606,0x170D0D0D,0x0D0D0D17,0x17170F17
	.word 0x0F170F0E,0x0F0F0F0F,0x0B080B0E,0x170F0F0F,0x08081408,0x0F17170F,0x0F080908,0x0F0F170F
	.word 0x01010F0F,0x01010101,0x01010F17,0x01010101,0x01010F0F,0x01010101,0x0F0F0D0D,0x01010101
	.word 0x01010F0F,0x01010101,0x01010F0F,0x01010101,0x01010F01,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x10140B00,0x090B1010,0x0B240001,0x09040B0B,0x00000101,0x181C0909,0x01010101,0x1A131C00
	.word 0x00010101,0x210C131C,0x13000101,0x21212121,0x21000101,0x1A0C2121,0x1A000101,0x221A0C0C
	.word 0x0F080808,0x010F170F,0x13181C18,0x01010F17,0x1A1A1A13,0x01010F0F,0x16161A1A,0x01010F00
	.word 0x140B161A,0x01010100,0x260B001A,0x01010016,0x0B14001A,0x01010016,0x19191900,0x01010016
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x00010101,0x22221A1A,0x22000101,0x00222222,0x12000101,0x00221215,0x00010101,0x12121512
	.word 0x00010101,0x22221A0C,0x01010101,0x1A08001F,0x01010101,0x0E0E0001,0x01010101,0x04040E01
	.word 0x19020219,0x01010019,0x02191E1F,0x01010100,0x1E191F10,0x01010100,0x000B0B1F,0x01010100
	.word 0x00000022,0x0101011F,0x081A001A,0x01010101,0x00081A0E,0x01010101,0x01080E0E,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01170101
	.word 0x01010101,0x170D1701,0x01010101,0x0D170D0F,0x01010101,0x0D0F0D0F,0x01010101,0x0D0D0F01
	.word 0x01010101,0x01010101,0x01010101,0x0D17170F,0x17170801,0x0606060D,0x06060D17,0x06060606
	.word 0x0D06060D,0x060D0D0D,0x0D0D0D06,0x17170D0D,0x170D0611,0x060D1717,0x06111106,0x0D060606
	.word 0x01010101,0x01010101,0x17170D0D,0x01010101,0x06110606,0x0101170D,0x11060606,0x01170D06
	.word 0x11110617,0x0F0D0611,0x060D170D,0x0D061106,0x0D0D170D,0x0D06060D,0x17060D17,0x0D060D0D
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x0101010F,0x01010101,0x01010117,0x01010101,0x01010F0D,0x01010101

	.word 0x01010101,0x17170F01,0x01010101,0x0F0D170F,0x01010101,0x0F170D0F,0x01010101,0x0F170D00
	.word 0x01010101,0x00170001,0x01010101,0x0E000101,0x01010101,0x08010101,0x01010101,0x00010101
	.word 0x060D0D17,0x170F0D06,0x0D170F0F,0x1717080D,0x000D170E,0x0D040400,0x0800160E,0x0D080816
	.word 0x0A0E0B0E,0x0F080300,0x00140B0E,0x0E080A00,0x1D14040E,0x0B0E0A1D,0x1B10040B,0x0B140A1B
	.word 0x0D060D17,0x0D0D1717,0x06061717,0x1717170D,0x0D0D170D,0x0F170606,0x17170606,0x170D0D0D
	.word 0x0D0D0D17,0x17170F17,0x0F170F0E,0x0F0F0F0F,0x0B080B0E,0x170F0F0F,0x08081408,0x0F17170F
	.word 0x01010F0D,0x01010101,0x01010F0F,0x01010101,0x01010F17,0x01010101,0x01010F0F,0x01010101
	.word 0x0F0F0D0D,0x01010101,0x01010F0F,0x01010101,0x01010F0F,0x01010101,0x01010F01,0x01010101

	.word 0x01010101,0x1F010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x1010100B,0x0B101010,0x10140B00,0x090B1010,0x0B240001,0x09040B0B,0x00000101,0x181C0909
	.word 0x01010101,0x1A131C00,0x00010101,0x210C131C,0x13000101,0x21212121,0x21000101,0x1A0C2121
	.word 0x0F080908,0x0F0F170F,0x0F080808,0x010F170F,0x13181C18,0x01010F17,0x1A1A1A13,0x01010F0F
	.word 0x16161A1A,0x01010F00,0x140B161A,0x01010116,0x2616001A,0x0101000B,0x0B16001A,0x0100160B
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x1A000001,0x221A0C0C,0x00190200,0x22221A1A,0x22000B09,0x00222222,0x12000901,0x00221215
	.word 0x00090101,0x12121512,0x21000101,0x22221A0C,0x0E0E0001,0x0000250E,0x04040E01,0x01000E04
	.word 0x19191900,0x01001919,0x02190907,0x01001902,0x1E1F000E,0x01000219,0x1F10081F,0x01001E19
	.word 0x0B1F001F,0x0101000B,0x00000022,0x01010800,0x0E0E0001,0x0101000E,0x00000101,0x01010100
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x17010101,0x01010101,0x0D0F0101
	.word 0x01010101,0x01010101,0x01010101,0x0D0D1717,0x0D170101,0x06061106,0x060D1701,0x06060611
	.word 0x11060D0F,0x17061111,0x0611060D,0x0D170D06,0x0D06060D,0x0D170D0D,0x0D0D060D,0x170D0617
	.word 0x01010101,0x01010101,0x0F17170D,0x01010101,0x0D060606,0x01081717,0x06060606,0x170D0606
	.word 0x0D0D0D06,0x0D06060D,0x0D0D1717,0x060D0D0D,0x17170D06,0x11060D17,0x0606060D,0x06111106
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01011701,0x01010101
	.word 0x01170D17,0x01010101,0x0F0D170D,0x01010101,0x0F0D0F0D,0x01010101,0x010F0D0D,0x01010101

	.word 0x01010101,0x0D0F0101,0x01010101,0x0F0F0101,0x01010101,0x170F0101,0x01010101,0x0F0F0101
	.word 0x01010101,0x0D0D0F0F,0x01010101,0x0F0F0101,0x01010101,0x0F0F0101,0x01010101,0x010F0101
	.word 0x17170D0D,0x170D060D,0x0D171717,0x17170606,0x0606170F,0x0D170D0D,0x0D0D0D17,0x06061717
	.word 0x170F1717,0x170D0D0D,0x0F0F0F0F,0x0E0F170F,0x0F0F0F17,0x0E0B080B,0x0F17170F,0x08140808
	.word 0x060D0F17,0x170D0D06,0x0D081717,0x0F0F170D,0x0004040D,0x0E170D00,0x1608080D,0x0E160008
	.word 0x0003080F,0x0E0B0E0A,0x000A080E,0x0E0B1400,0x1D0A0E0B,0x0E04141D,0x1B0A140B,0x0B04101B
	.word 0x010F1717,0x01010101,0x0F170D0F,0x01010101,0x0F0D170F,0x01010101,0x000D170F,0x01010101
	.word 0x01001700,0x01010101,0x0101000E,0x01010101,0x01010108,0x01010101,0x01010100,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x0F170F0F,0x0809080F,0x0F170F01,0x0808080F,0x170F0101,0x1C1C1813,0x0F0F0101,0x131A1A1A
	.word 0x000F0101,0x1A1A1616,0x00010101,0x1A160B14,0x16000101,0x1A000B26,0x16000101,0x00191916
	.word 0x1010100B,0x0B101010,0x10100B09,0x000B1410,0x0B0B0409,0x0100240B,0x09091C18,0x01010000
	.word 0x0018131A,0x01010101,0x18130C21,0x01010100,0x21212121,0x01010013,0x21210C1A,0x01010021
	.word 0x0101011F,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x1A000101,0x02021919,0x00010101,0x1E19021A,0x00010101,0x1F191E1A,0x23000101,0x0B0B0000
	.word 0x071F0001,0x2424081F,0x1F0E0001,0x1A000000,0x0E040001,0x1A000E0E,0x040E0101,0x01000404
	.word 0x0C0C1A19,0x0101001A,0x1A1A001F,0x01010100,0x22220010,0x01010022,0x1512121F,0x01010012
	.word 0x1215121F,0x01010100,0x001A1A1F,0x0101000E,0x0E0E001A,0x0101000E,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x0F010101,0x01010101,0x17010101,0x01010101,0x0D0F0101,0x01010101,0x0D0F0101
	.word 0x01010101,0x0D0D1717,0x0D170101,0x06061106,0x060D1701,0x06060611,0x11060D0F,0x17061111
	.word 0x0611060D,0x0D170D06,0x0D06060D,0x0D170D0D,0x0D0D060D,0x170D0617,0x17170D0D,0x170D060D
	.word 0x0F17170D,0x01010101,0x0D060606,0x01081717,0x06060606,0x170D0606,0x0D0D0D06,0x0D06060D
	.word 0x0D0D1717,0x060D0D0D,0x17170D06,0x11060D17,0x0606060D,0x06111106,0x060D0F17,0x170D0D06
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01011701,0x01010101,0x01170D17,0x01010101
	.word 0x0F0D170D,0x01010101,0x0F0D0F0D,0x01010101,0x010F0D0D,0x01010101,0x010F1717,0x01010101

	.word 0x01010101,0x0F0F0101,0x01010101,0x170F0101,0x01010101,0x0F0F0101,0x01010101,0x0D0D0F0F
	.word 0x01010101,0x0F0F0101,0x01010101,0x0F0F0101,0x01010101,0x010F0101,0x01010101,0x01010101
	.word 0x0D171717,0x17170606,0x0606170F,0x0D170D0D,0x0D0D0D17,0x06061717,0x170F1717,0x170D0D0D
	.word 0x0F0F0F0F,0x0E0F170F,0x0F0F0F17,0x0E0B080B,0x0F17170F,0x08140808,0x0F170F0F,0x0809080F
	.word 0x0D081717,0x0F0F170D,0x0004040D,0x0E170D00,0x1608080D,0x0E160008,0x0003080F,0x0E0B0E0A
	.word 0x000A080E,0x0E0B1400,0x1D0A0E0B,0x0E04141D,0x1B0A140B,0x0B04101B,0x1010100B,0x0B101010
	.word 0x0F170D0F,0x01010101,0x0F0D170F,0x01010101,0x000D170F,0x01010101,0x01001700,0x01010101
	.word 0x0101000E,0x01010101,0x01010108,0x01010101,0x01010100,0x01010101,0x0101011F,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x0F170F01,0x0808080F,0x170F0101,0x181C1813,0x0F0F0101,0x131A1A1A,0x000F0101,0x1A1A1616
	.word 0x00010101,0x1A160B14,0x16000101,0x1A000B26,0x16000101,0x1A00140B,0x16000101,0x00191919
	.word 0x10100B09,0x000B1410,0x0B0B0409,0x0100240B,0x09091C18,0x01010000,0x001C131A,0x01010101
	.word 0x1C130C21,0x01010100,0x21212121,0x01010013,0x21210C1A,0x01010021,0x0C0C1A22,0x0101001A
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x19000101,0x19020219,0x00010101,0x1F1E1902,0x00010101,0x101F191E,0x00010101,0x1F0B0B00
	.word 0x1F010101,0x22000000,0x01010101,0x1A001A08,0x01010101,0x0E1A0800,0x01010101,0x0E0E0801
	.word 0x1A1A2222,0x01010100,0x22222200,0x01010022,0x15122200,0x01010012,0x12151212,0x01010100
	.word 0x0C1A2222,0x01010100,0x1F00081A,0x01010101,0x01000E0E,0x01010101,0x010E0404,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x17010101,0x01010101,0x0D0F0101
	.word 0x01010101,0x01010101,0x01010101,0x0D0D1717,0x0D170101,0x06061106,0x060D1701,0x06060611
	.word 0x11060D0F,0x17061111,0x0611060D,0x0D170D06,0x0D06060D,0x0D170D0D,0x0D0D060D,0x170D0617
	.word 0x01010101,0x01010101,0x0F17170D,0x01010101,0x0D060606,0x01081717,0x06060606,0x170D0606
	.word 0x0D0D0D06,0x0D06060D,0x0D0D1717,0x060D0D0D,0x17170D06,0x11060D17,0x0606060D,0x06111106
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01011701,0x01010101
	.word 0x01170D17,0x01010101,0x0F0D170D,0x01010101,0x0F0D0F0D,0x01010101,0x010F0D0D,0x01010101

	.word 0x01010101,0x0D0F0101,0x01010101,0x0F0F0101,0x01010101,0x170F0101,0x01010101,0x0F0F0101
	.word 0x01010101,0x0D0D0F0F,0x01010101,0x0F0F0101,0x01010101,0x0F0F0101,0x01010101,0x010F0101
	.word 0x17170D0D,0x170D060D,0x0D171717,0x17170606,0x0606170F,0x0D170D0D,0x0D0D0D17,0x06061717
	.word 0x170F1717,0x170D0D0D,0x0F0F0F0F,0x0E0F170F,0x0F0F0F17,0x0E0B080B,0x0F17170F,0x08140808
	.word 0x060D0F17,0x170D0D06,0x0D081717,0x0F0F170D,0x0004040D,0x0E170D00,0x1608080D,0x0E160008
	.word 0x0003080F,0x0E0B0E0A,0x000A080E,0x0E0B1400,0x1D0A0E0B,0x0E04141D,0x1B0A140B,0x0B04101B
	.word 0x010F1717,0x01010101,0x0F170D0F,0x01010101,0x0F0D170F,0x01010101,0x000D170F,0x01010101
	.word 0x01001700,0x01010101,0x0101000E,0x01010101,0x01010108,0x01010101,0x01010100,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x0F170F0F,0x0809080F,0x0F170F01,0x0808080F,0x170F0101,0x181C1813,0x0F0F0101,0x131A1A1A
	.word 0x000F0101,0x1A1A1616,0x16010101,0x1A160B14,0x0B000101,0x1A001626,0x0B160001,0x1A00160B
	.word 0x1010100B,0x0B101010,0x10100B09,0x000B1410,0x0B0B0409,0x0100240B,0x09091C18,0x01010000
	.word 0x001C131A,0x01010101,0x1C130C21,0x01010100,0x21212121,0x01010013,0x21210C1A,0x01010021
	.word 0x0101011F,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x19190001,0x00191919,0x02190001,0x07091902,0x19020001,0x0E001F1E,0x191E0001,0x1F08101F
	.word 0x0B000101,0x1F001F0B,0x00080101,0x22000000,0x0E000101,0x01000E0E,0x00010101,0x01010000
	.word 0x0C0C1A22,0x0100001A,0x1A1A2222,0x00021900,0x22222200,0x090B0022,0x15122200,0x01090012
	.word 0x12151212,0x01010900,0x0C1A2222,0x01010021,0x0E250000,0x01000E0E,0x040E0001,0x010E0404
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x0D170101
	.word 0x01010101,0x01010101,0x01010101,0x0D0D1717,0x17170101,0x060D0D0D,0x110D1701,0x06060611
	.word 0x11060D17,0x06060606,0x1111110F,0x06060611,0x06110611,0x06061106,0x06060606,0x06060611
	.word 0x01010101,0x01010101,0x170D0D0D,0x01010F17,0x06060606,0x0F170D0D,0x0D0D0D06,0x0D06060D
	.word 0x0D060606,0x06060606,0x0D060606,0x11060606,0x06060606,0x06060606,0x06060606,0x11060606
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x010F0F0F,0x01010101
	.word 0x01010F0D,0x01010101,0x01011706,0x01010101,0x010F0D06,0x01010101,0x01170D0D,0x01010101

	.word 0x01010101,0x11080101,0x01010101,0x17080101,0x01010101,0x0D170801,0x01010101,0x06170801
	.word 0x01010101,0x0D060801,0x01010101,0x170D0D0F,0x01010101,0x0017170F,0x01010101,0x1717010F
	.word 0x11060D06,0x11060606,0x0606060D,0x0611060D,0x170D0606,0x0606060D,0x0D170F0D,0x060D0606
	.word 0x060D170F,0x060D170D,0x0D06060D,0x060D1717,0x170D170F,0x060D0F17,0x0F170F0F,0x0D17170F
	.word 0x11060606,0x0611060D,0x11060611,0x0D060D06,0x060D0611,0x06060D06,0x060D0606,0x060D0606
	.word 0x0D170D06,0x060D0606,0x17171706,0x0D17060D,0x170F170D,0x170F0D17,0x170F1717,0x0000170F
	.word 0x17171717,0x01010101,0x08060D06,0x01010101,0x0D170606,0x01010101,0x0F060D0D,0x01010101
	.word 0x0F0D0D17,0x01010101,0x0D0F0D08,0x0101010F,0x0F0F0F08,0x0101010F,0x01170F0F,0x0101010F

	.word 0x01010101,0x0F010101,0x01010101,0x17010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x00010101,0x01010101,0x08010101,0x01010101,0x19080101
	.word 0x0F0F0F17,0x170F170F,0x0F0F0F00,0x0F0F1717,0x17170F08,0x0F0F0F17,0x1F1A0001,0x0F0F1717
	.word 0x0C1A1600,0x0F1A1721,0x0C1A0B16,0x0F181A1A,0x1A0C1616,0x1A1A0C0C,0x08081619,0x20210C1A
	.word 0x170F0F17,0x0F0F0F0F,0x170F0F17,0x000F0F0F,0x170F0F17,0x171F0F17,0x170F0F17,0x001F1F1A
	.word 0x17170F17,0x160B2113,0x1A181C17,0x0B0B160C,0x20210C0C,0x140B1A20,0x20202020,0x1F16080C
	.word 0x01011708,0x01010101,0x01011708,0x01010101,0x01010108,0x01010101,0x01010101,0x01010101
	.word 0x01010100,0x01010101,0x01010108,0x01010101,0x01010816,0x01010101,0x0101001F,0x01010101

	.word 0x01010101,0x02080101,0x01010101,0x08010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x00081919,0x210C1A1A,0x05081902,0x1A1A1A12,0x22080000,0x22221215,0x12050001,0x12121515
	.word 0x1F000101,0x15151222,0x00010101,0x05210C08,0x01010101,0x04040E00,0x01010101,0x00000001
	.word 0x0C202121,0x191F001A,0x1A0C1A1A,0x02190522,0x12122222,0x19080822,0x22221512,0x0008000C
	.word 0x0C082212,0x01010000,0x08000005,0x01010101,0x0101011F,0x01010101,0x01010101,0x01010101
	.word 0x01001F02,0x01010101,0x01001E02,0x01010101,0x0100020B,0x01010101,0x01010000,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x0D170101,0x01010101,0x11080101
	.word 0x01010101,0x0D0D1717,0x17170101,0x060D0D0D,0x110D1701,0x06060611,0x11060D17,0x06060606
	.word 0x1111110F,0x06060611,0x06110611,0x06061106,0x06060606,0x06060611,0x11060D06,0x11060606
	.word 0x170D0D0D,0x01010F17,0x06060606,0x0F170D0D,0x0D0D0D06,0x0D06060D,0x0D060606,0x06060606
	.word 0x0D060606,0x11060606,0x06060606,0x06060606,0x06060606,0x11060606,0x11060606,0x0611060D
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x010F0F0F,0x01010101,0x01010F0D,0x01010101
	.word 0x01011706,0x01010101,0x010F0D06,0x01010101,0x01170D0D,0x01010101,0x17171717,0x01010101

	.word 0x01010101,0x17080101,0x01010101,0x0D170801,0x01010101,0x06170801,0x01010101,0x0D060801
	.word 0x01010101,0x170D0D0F,0x01010101,0x0017170F,0x01010101,0x1717010F,0x01010101,0x0F010101
	.word 0x0606060D,0x0611060D,0x170D0606,0x0606060D,0x0D170F0D,0x060D0606,0x060D170F,0x060D170D
	.word 0x0D06060D,0x060D1717,0x170D170F,0x060D0F17,0x0F170F0F,0x0D17170F,0x0F0F0F17,0x170F170F
	.word 0x11060611,0x0D060D06,0x060D0611,0x06060D06,0x060D0606,0x060D0606,0x0D170D06,0x060D0606
	.word 0x17171706,0x0D17060D,0x170F170D,0x170F0D17,0x170F1717,0x0000170F,0x170F0F17,0x0F0F0F0F
	.word 0x08060D06,0x01010101,0x0D170606,0x01010101,0x0F060D0D,0x01010101,0x0F0D0D17,0x01010101
	.word 0x0D0F0D08,0x0101010F,0x0F0F0F08,0x0101010F,0x01170F0F,0x0101010F,0x01011708,0x01010101

	.word 0x01010101,0x17010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x00010101,0x01010101,0x00010101,0x01010101,0x19000101,0x01010101,0x02190001
	.word 0x0F0F0F00,0x0F0F1717,0x17170F08,0x0F0F0F17,0x1F1A0001,0x0F0F1717,0x211A1600,0x0F1A1713
	.word 0x211A1616,0x0F181A1A,0x1A210B16,0x1A1A2121,0x08080B14,0x21212121,0x00081919,0x21210C1A
	.word 0x170F0F17,0x000F0F0F,0x170F0F17,0x171F0F17,0x170F0F17,0x001F1F1A,0x17170F17,0x161A2113
	.word 0x1A181C17,0x161A211A,0x211A1A1A,0x0B211A21,0x21212121,0x0B080821,0x0C212121,0x1908001A
	.word 0x01011708,0x01010101,0x01010108,0x01010101,0x01010101,0x01010101,0x01010100,0x01010101
	.word 0x01010016,0x01010101,0x01010016,0x01010101,0x01001914,0x01010101,0x00190219,0x01010101

	.word 0x01010101,0x1E190001,0x01010101,0x02000101,0x01010101,0x00010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x05081902,0x1A0C1A12,0x22081F02,0x22221212,0x12050000,0x12121522,0x22050101,0x15150522
	.word 0x05000101,0x05210C08,0x00010101,0x080E0404,0x00010101,0x000E0E1F,0x01010101,0x01000000
	.word 0x1A0C1A1A,0x19080512,0x12222222,0x1F082212,0x15121212,0x00051222,0x05151515,0x01052222
	.word 0x0C050505,0x01000508,0x040E0800,0x01010004,0x0E0E0000,0x0101001F,0x00000101,0x01010100
	.word 0x00191E02,0x01010101,0x01000202,0x01010101,0x01010000,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x0F010101,0x01010101,0x0D170101
	.word 0x01010101,0x01010101,0x01010101,0x0D0D1717,0x17170101,0x060D0D0D,0x110D1701,0x06060611
	.word 0x11060D17,0x06060606,0x1111110F,0x06060611,0x06110611,0x06061106,0x06060606,0x06060611
	.word 0x01010101,0x01010101,0x170D0D0D,0x01010F17,0x06060606,0x0F170D0D,0x0D0D0D06,0x0D06060D
	.word 0x0D060606,0x06060606,0x0D060606,0x11060606,0x06060606,0x06060606,0x06060606,0x11060606
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x010F0F0F,0x01010101
	.word 0x01010F0D,0x01010101,0x01011706,0x01010101,0x010F0D06,0x01010101,0x01170D0D,0x01010101

	.word 0x01010101,0x11080101,0x01010101,0x17080101,0x01010101,0x0D170801,0x01010101,0x06170801
	.word 0x01010101,0x0D060801,0x01010101,0x170D0D0F,0x01010101,0x0017170F,0x01010101,0x1717010F
	.word 0x11060D06,0x11060606,0x0606060D,0x0611060D,0x170D0606,0x0606060D,0x0D170F0D,0x060D0606
	.word 0x060D170F,0x060D170D,0x0D06060D,0x060D1717,0x170D170F,0x060D0F17,0x0F170F0F,0x0D17170F
	.word 0x11060606,0x0611060D,0x11060611,0x0D060D06,0x060D0611,0x06060D06,0x060D0606,0x060D0606
	.word 0x0D170D06,0x060D0606,0x17171706,0x0D17060D,0x170F170D,0x170F0D17,0x170F1717,0x0000170F
	.word 0x17171717,0x01010101,0x08060D06,0x01010101,0x0D170606,0x01010101,0x0F060D0D,0x01010101
	.word 0x0F0D0D17,0x01010101,0x0D0F0D08,0x0101010F,0x0F0F0F08,0x0101010F,0x01170F0F,0x0101010F

	.word 0x01010101,0x0F010101,0x01010101,0x17010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x08010101,0x01010101,0x00010101
	.word 0x0F0F0F17,0x170F170F,0x0F0F0F00,0x0F0F1717,0x17170F08,0x0F0F0F17,0x1F1F0001,0x0F0F171A
	.word 0x210B1600,0x0F1A1713,0x160B0B08,0x1C181A0C,0x1A0B1416,0x0C212020,0x08161F1F,0x2020200C
	.word 0x170F0F17,0x0F0F0F0F,0x170F0F17,0x000F0F0F,0x170F0F17,0x171F0F17,0x170F0F17,0x001A1F1A
	.word 0x17170F17,0x161A0C21,0x1A182017,0x0B1A0C1A,0x0C1A1A0C,0x160C1A0C,0x0C212020,0x1608081A
	.word 0x01011708,0x01010101,0x01011708,0x01010101,0x01010108,0x01010101,0x01010101,0x01010101
	.word 0x01010100,0x01010101,0x01010016,0x01010101,0x01010816,0x01010101,0x01081919,0x01010101

	.word 0x01010101,0x1F000101,0x01010101,0x1E000101,0x01010101,0x02000101,0x01010101,0x00010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x001F1902,0x21200C1A,0x05190202,0x1A0C1A22,0x0808190B,0x22121222,0x00080000,0x1522220C
	.word 0x00010101,0x22080C00,0x01010101,0x00000801,0x01010101,0x01010101,0x01010101,0x01010101
	.word 0x1A0C2121,0x1908001A,0x1A1A1A1A,0x19080512,0x12222222,0x00082215,0x15121212,0x00051215
	.word 0x12151512,0x01001F22,0x0C210505,0x01010008,0x0E04041F,0x01010100,0x00000001,0x01010101
	.word 0x01080219,0x01010101,0x01010802,0x01010101,0x01010100,0x01010101,0x01010101,0x01010101
	.word 0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101,0x01010101

	.section .rodata
	.align	2
	.global manPal		@ 512 unsigned chars
manPal:
	.hword 0x0000,0x7C1F,0x15CA,0x76E7,0x2DD3,0x0486,0x49D3,0x2548
	.hword 0x0842,0x00CA,0x6B5A,0x2A3A,0x28E6,0x352F,0x190B,0x1064
	.hword 0x575F,0x5256,0x0931,0x51EE,0x42DD,0x0DD6,0x14EE,0x20A9
	.hword 0x62B4,0x0D06,0x1CA4,0x18D4,0x7F9B,0x084D,0x1A4F,0x14A6
	.hword 0x418A,0x3548,0x08EB,0x3E52,0x0552,0x10C6,0x577F,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(man)