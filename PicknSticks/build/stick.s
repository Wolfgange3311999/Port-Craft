
@{{BLOCK(stick)

@=======================================================================
@
@	stick, 32x32@8, 
@	Transparent color : FF,00,FF
@	+ palette 256 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 512 + 1024 = 1536
@
@	Time-stamp: 2012-01-30, 20:37:43
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.9
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global stickTiles		@ 1024 unsigned chars
stickTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x04000000
	.word 0x00000000,0x0C0C0000,0x00000000,0x32150C00,0x00000000,0x3232150C,0x04000000,0x3232320C
	.word 0x00000000,0x00000000,0x18000000,0x06241818,0x04040400,0x181E0404,0x0C0C0C0C,0x1804040C
	.word 0x0C0C1515,0x1E04040C,0x0C0C3232,0x1E04040C,0x0C0C3232,0x1804040C,0x0C0C3232,0x1804040C
	.word 0x00000000,0x00000000,0x0F312520,0x00000019,0x31250624,0x0007190F,0x25200618,0x07190F02
	.word 0x25200618,0x07190F31,0x25200618,0x23190F31,0x20200618,0x192D2231,0x20202418,0x2D2D2212
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0000002C,0x00000000
	.word 0x00002C2E,0x00000000,0x0001211D,0x00000000,0x2F2F1D23,0x00000000,0x16211D23,0x0000002F

	.word 0x0C000000,0x32323215,0x0C040000,0x32323215,0x0C040000,0x0C0C0C0C,0x0C041800,0x0C0C0C0C
	.word 0x0C041800,0x0C0C0C0C,0x04041800,0x04040404,0x041E2400,0x04040404,0x18180600,0x18181E1E
	.word 0x0C0C0C32,0x181E0404,0x0C0C0C0C,0x1E1E0404,0x040C0C0C,0x0E1E1E04,0x04040C0C,0x0E0E1E1E
	.word 0x1E040404,0x0E0E1E1E,0x1E1E0404,0x280E0E1E,0x0E1E1E1E,0x28280E0E,0x0E0E1E18,0x0B28280E
	.word 0x121A2424,0x052A2212,0x121A1A24,0x052A2626,0x0B1A1A24,0x1B2A1026,0x0B0B1A28,0x1B1B1026
	.word 0x2B0B0B28,0x1C1B1010,0x2B2B0B1A,0x1C1B0910,0x172B0B0B,0x1C1C0910,0x17172B0B,0x0D1C0909
	.word 0x16303323,0x00000016,0x0A301F27,0x00001616,0x0A111F27,0x00000A0A,0x11111427,0x00160A11
	.word 0x11111427,0x000A1111,0x11030314,0x00111111,0x03030314,0x00110303,0x03030303,0x00110303

	.word 0x18242000,0x18181818,0x06062500,0x24060606,0x20253100,0x20202020,0x25310F00,0x20202525
	.word 0x020F1900,0x12313131,0x0F190000,0x22220F0F,0x19070000,0x2D2D1919,0x07000000,0x2D192307
	.word 0x28242424,0x0B0B1A28,0x1A1A1A24,0x2B0B0B0B,0x0B1A1A1A,0x172B2B0B,0x0B0B1212,0x17172B2B
	.word 0x26262612,0x09101010,0x10102622,0x09090910,0x1B2A2A2A,0x1C1C1B1B,0x1B1B0505,0x0D1C1C1C
	.word 0x09172B2B,0x0D0D2909,0x0909172B,0x080D2929,0x29090917,0x08080D29,0x29290909,0x0808080D
	.word 0x0D292909,0x08080808,0x080D2929,0x13080808,0x08080D0D,0x13130808,0x0808080D,0x13131308
	.word 0x08080303,0x00030303,0x08080808,0x00030808,0x08080808,0x00030808,0x08080808,0x00030808
	.word 0x08131308,0x00030808,0x13131313,0x00000808,0x13131313,0x00000808,0x13131313,0x00000008

	.word 0x2C000000,0x23231D2E,0x00000000,0x1D1D212C,0x00000000,0x212F0100,0x00000000,0x162F0000
	.word 0x00000000,0x2F000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x27272723,0x03141427,0x141F1F33,0x03030314,0x11113030,0x03030311,0x110A0A16,0x03031111
	.word 0x110A1616,0x03031111,0x0A0A1600,0x03031111,0x16000000,0x1111110A,0x00000000,0x00000000
	.word 0x08080803,0x13131308,0x08080803,0x13131313,0x08080808,0x13131313,0x08080808,0x13131308
	.word 0x08080803,0x08080808,0x08080803,0x00080808,0x03030303,0x00000003,0x00000000,0x00000000
	.word 0x13131313,0x00000008,0x08131313,0x00000000,0x00081313,0x00000000,0x00000813,0x00000000
	.word 0x00000008,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global stickPal		@ 512 unsigned chars
stickPal:
	.hword 0x7C1F,0x1085,0x252B,0x2525,0x35AF,0x2528,0x2D6D,0x1CE8
	.hword 0x2945,0x2D68,0x1CE5,0x318B,0x39D0,0x2946,0x35AD,0x252A
	.hword 0x2D69,0x2105,0x2D6B,0x2D65,0x2526,0x39D1,0x18C5,0x3189
	.hword 0x318E,0x2109,0x318C,0x2948,0x2947,0x1CE7,0x35AE,0x2106
	.hword 0x2D6C,0x18C6,0x294A,0x2108,0x318D,0x294C,0x2D6A,0x2527
	.hword 0x35AC,0x2D67,0x2949,0x318A,0x14A6,0x2529,0x18C7,0x14A5
	.hword 0x1CE6,0x294B,0x3DF1,0x2107,0x0000,0x0000,0x0000,0x0000
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

@}}BLOCK(stick)
