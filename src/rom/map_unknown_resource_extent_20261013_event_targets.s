; Native event destination coordinates and fade state words; no scene payload.
.setcpu "65816"
.segment "CODE"
.org $7A80
.macro scroll_target cell_x, cell_y
    .byte cell_x, cell_y
.endmacro
map_unknown_resource_extent_20261013_scroll_targets:
    scroll_target $08, $08
    scroll_target $18, $08
    scroll_target $28, $08
    scroll_target $38, $08
    scroll_target $08, $18
    scroll_target $18, $18
    scroll_target $28, $18
    scroll_target $38, $18
    scroll_target $08, $28
    scroll_target $18, $28
    scroll_target $28, $28
    scroll_target $38, $28
    scroll_target $08, $38
    scroll_target $18, $38
    scroll_target $28, $38
    scroll_target $38, $38
    scroll_target $98, $C8
    scroll_target $04, $04
    scroll_target $0C, $04
    scroll_target $85, $B8
    scroll_target $1C, $04
    scroll_target $D4, $42
    scroll_target $18, $98
    scroll_target $88, $D3
    scroll_target $17, $CB
    scroll_target $86, $CB
    scroll_target $17, $C9
    scroll_target $7F, $C1
    scroll_target $7D, $B8
    scroll_target $7D, $B8
    scroll_target $7D, $B8
    scroll_target $7D, $B8
    scroll_target $04, $04
    scroll_target $39, $5E
    scroll_target $38, $59
    scroll_target $38, $59
    scroll_target $04, $0C
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $78, $98
    scroll_target $78, $98
    scroll_target $78, $98
    scroll_target $14, $14
    scroll_target $1C, $14
    scroll_target $04, $1C
    scroll_target $0C, $1C
    scroll_target $14, $1C
    scroll_target $77, $A3
    scroll_target $38, $59
    scroll_target $87, $8F
    scroll_target $14, $04
    scroll_target $68, $89
    scroll_target $88, $A8
    scroll_target $98, $A8
    scroll_target $98, $98
    scroll_target $88, $98
    scroll_target $77, $A8
    scroll_target $7A, $8B
    scroll_target $88, $9C
    scroll_target $88, $9C
    scroll_target $77, $A5
    scroll_target $4E, $B3
    scroll_target $4E, $B3
    scroll_target $49, $A8
    scroll_target $47, $A5
    scroll_target $47, $A5
    scroll_target $47, $A5
    scroll_target $30, $6D
    scroll_target $30, $6D
    scroll_target $30, $6D
    scroll_target $30, $6D
    scroll_target $1C, $0C
    scroll_target $04, $14
    scroll_target $0C, $14
    scroll_target $14, $14
    scroll_target $9B, $0E
    scroll_target $98, $16
    scroll_target $92, $2A
    scroll_target $8A, $0E
    scroll_target $94, $1C
    scroll_target $AB, $1A
    scroll_target $A8, $26
    scroll_target $C6, $43
    scroll_target $94, $1C
    scroll_target $37, $77
    scroll_target $37, $77
    scroll_target $37, $77
    scroll_target $37, $77
    scroll_target $37, $77
    scroll_target $28, $5C
    scroll_target $18, $68
    scroll_target $2A, $74
    scroll_target $2A, $74
    scroll_target $17, $74
    scroll_target $38, $68
    scroll_target $68, $77
    scroll_target $38, $77
    scroll_target $43, $59
    scroll_target $14, $04
    scroll_target $1C, $04
    scroll_target $C6, $43
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $1C, $0C
    scroll_target $04, $14
    scroll_target $0C, $14
    scroll_target $14, $14
    scroll_target $1C, $14
    scroll_target $04, $1C
    scroll_target $87, $B5
    scroll_target $98, $F7
    scroll_target $1C, $1C
    scroll_target $98, $F9
    scroll_target $87, $57
    scroll_target $DD, $67
    scroll_target $C8, $47
    scroll_target $88, $57
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $1C, $0C
    scroll_target $04, $14
    scroll_target $0C, $14
    scroll_target $14, $14
    scroll_target $1C, $14
    scroll_target $04, $1C
    scroll_target $0C, $1C
    scroll_target $14, $1C
    scroll_target $1C, $1C
    scroll_target $98, $BD
    scroll_target $98, $BD
    scroll_target $98, $BD
    scroll_target $98, $BD
    scroll_target $87, $BD
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $1C, $0C
    scroll_target $83, $B6
    scroll_target $0C, $14
    scroll_target $14, $14
    scroll_target $1C, $14
    scroll_target $04, $1C
    scroll_target $0C, $1C
    scroll_target $14, $1C
    scroll_target $1C, $1C
    scroll_target $99, $D8
    scroll_target $99, $D8
    scroll_target $14, $04
    scroll_target $1C, $04
    scroll_target $04, $0C
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $1C, $0C
    scroll_target $04, $14
    scroll_target $0C, $14
    scroll_target $14, $14
    scroll_target $E4, $65
    scroll_target $B1, $26
    scroll_target $2B, $5D
    scroll_target $9F, $AA
    scroll_target $81, $C2
    scroll_target $98, $DB
    scroll_target $0C, $04
    scroll_target $14, $04
    scroll_target $1C, $04
    scroll_target $04, $0C
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $1C, $0C
    scroll_target $7C, $D9
    scroll_target $0C, $14
    scroll_target $97, $DC
    scroll_target $1C, $14
    scroll_target $49, $A8
    scroll_target $49, $A8
    scroll_target $14, $1C
    scroll_target $1C, $1C
    scroll_target $49, $A8
    scroll_target $0C, $04
    scroll_target $14, $04
    scroll_target $1C, $04
    scroll_target $04, $0C
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $1C, $0C
    scroll_target $04, $14
    scroll_target $0C, $14
    scroll_target $14, $14
    scroll_target $1C, $14
    scroll_target $04, $1C
    scroll_target $0C, $1C
    scroll_target $14, $1C
    scroll_target $1C, $1C
    scroll_target $04, $04
    scroll_target $0C, $04
    scroll_target $8D, $18
    scroll_target $D9, $D6
    scroll_target $7D, $B8
    scroll_target $8D, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $6A, $86
    scroll_target $6C, $89
    scroll_target $68, $88
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $A7, $0B
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $27, $18
    scroll_target $0C, $1C
    scroll_target $14, $1C
    scroll_target $1C, $1C
    scroll_target $04, $04
    scroll_target $0C, $04
    scroll_target $14, $04
    scroll_target $1C, $04
    scroll_target $04, $0C
    scroll_target $0C, $0C
    scroll_target $14, $0C
    scroll_target $1C, $0C
    scroll_target $04, $14
    scroll_target $0C, $14
    scroll_target $14, $14
    scroll_target $1C, $14
    scroll_target $04, $1C
    scroll_target $0C, $1C
    scroll_target $14, $1C
    scroll_target $EA, $00
.macro fade_target cell_x, cell_y, saved_transition_word
    .byte cell_x, cell_y
    .word saved_transition_word
.endmacro
map_unknown_resource_extent_20261013_fade_targets:
    fade_target $7C, $7C, $0404
    fade_target $6C, $7C, $0414
    fade_target $7C, $6C, $1404
    fade_target $6C, $6C, $1414
    fade_target $5C, $7C, $0424
    fade_target $4C, $7C, $0434
    fade_target $5C, $6C, $1424
    fade_target $4C, $6C, $1434
    fade_target $3C, $7C, $0444
    fade_target $2C, $7C, $0454
    fade_target $3C, $6C, $1444
    fade_target $2C, $6C, $1454
    fade_target $1C, $7C, $0464
    fade_target $0C, $7C, $0474
    fade_target $1C, $6C, $1464
    fade_target $0C, $6C, $1474
    fade_target $7C, $5C, $2404
    fade_target $6C, $5C, $2414
    fade_target $7C, $4C, $3404
    fade_target $6C, $4C, $3414
    fade_target $5C, $5C, $2424
    fade_target $4C, $5C, $2434
    fade_target $5C, $4C, $3424
    fade_target $4C, $4C, $3434
    fade_target $3C, $5C, $2444
    fade_target $2C, $5C, $2454
    fade_target $3C, $4C, $3444
    fade_target $2C, $4C, $3454
    fade_target $1C, $5C, $2464
    fade_target $0C, $5C, $2474
    fade_target $1C, $4C, $3464
    fade_target $0C, $4C, $3474
    fade_target $9B, $BF, $B784
    fade_target $9B, $BF, $CA85
    fade_target $7F, $C2, $D895
    fade_target $9B, $BF, $9888
    fade_target $7A, $8B, $7040
    fade_target $7A, $8B, $0BA7
    fade_target $9F, $AA, $BF9B
    fade_target $7A, $8B, $BF9B
    fade_target $7A, $8B, $8B7A
    fade_target $7F, $C2, $B784
    fade_target $9F, $AA, $CA85
    fade_target $9F, $AA, $D895
    fade_target $B1, $26, $8768
    fade_target $B1, $26, $5D28
    fade_target $2B, $5D, $8768
    fade_target $2B, $5D, $0BA7
    fade_target $2B, $5D, $65E4
    fade_target $E4, $65, $5C28
    fade_target $7A, $8B, $5C28
    fade_target $B1, $63, $7040
    fade_target $5C, $1C, $6424
    fade_target $4C, $1C, $6434
    fade_target $5C, $0C, $7424
    fade_target $4C, $0C, $7434
    fade_target $3C, $1C, $6444
    fade_target $2C, $1C, $6454
    fade_target $3C, $0C, $7444
    fade_target $2C, $0C, $7454
    fade_target $1C, $1C, $6464
    fade_target $0C, $1C, $6474
    fade_target $3B, $F6, $77BA
    fade_target $70, $F0, $AF94
