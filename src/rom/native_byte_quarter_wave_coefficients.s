; min(255, round(256*sin(index*pi/512))), index0..255.
.setcpu "65816"
.segment "CODE"
.org $7DE0
native_byte_quarter_wave_coefficients:
    .byte $00, $02, $03, $05, $06, $08, $09, $0B
    .byte $0D, $0E, $10, $11, $13, $14, $16, $18
    .byte $19, $1B, $1C, $1E, $1F, $21, $22, $24
    .byte $26, $27, $29, $2A, $2C, $2D, $2F, $30
    .byte $32, $33, $35, $37, $38, $3A, $3B, $3D
    .byte $3E, $40, $41, $43, $44, $46, $47, $49
    .byte $4A, $4C, $4D, $4F, $50, $52, $53, $55
    .byte $56, $58, $59, $5B, $5C, $5E, $5F, $61
    .byte $62, $63, $65, $66, $68, $69, $6B, $6C
    .byte $6D, $6F, $70, $72, $73, $75, $76, $77
    .byte $79, $7A, $7B, $7D, $7E, $80, $81, $82
    .byte $84, $85, $86, $88, $89, $8A, $8C, $8D
    .byte $8E, $90, $91, $92, $93, $95, $96, $97
    .byte $98, $9A, $9B, $9C, $9D, $9F, $A0, $A1
    .byte $A2, $A4, $A5, $A6, $A7, $A8, $AA, $AB
    .byte $AC, $AD, $AE, $AF, $B1, $B2, $B3, $B4
    .byte $B5, $B6, $B7, $B8, $B9, $BA, $BC, $BD
    .byte $BE, $BF, $C0, $C1, $C2, $C3, $C4, $C5
    .byte $C6, $C7, $C8, $C9, $CA, $CB, $CC, $CD
    .byte $CE, $CF, $CF, $D0, $D1, $D2, $D3, $D4
    .byte $D5, $D6, $D7, $D7, $D8, $D9, $DA, $DB
    .byte $DC, $DC, $DD, $DE, $DF, $E0, $E0, $E1
    .byte $E2, $E3, $E3, $E4, $E5, $E5, $E6, $E7
    .byte $E7, $E8, $E9, $E9, $EA, $EB, $EB, $EC
    .byte $ED, $ED, $EE, $EE, $EF, $EF, $F0, $F1
    .byte $F1, $F2, $F2, $F3, $F3, $F4, $F4, $F5
    .byte $F5, $F5, $F6, $F6, $F7, $F7, $F8, $F8
    .byte $F8, $F9, $F9, $F9, $FA, $FA, $FA, $FB
    .byte $FB, $FB, $FC, $FC, $FC, $FC, $FD, $FD
    .byte $FD, $FD, $FE, $FE, $FE, $FE, $FE, $FF
    .byte $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF
    .byte $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF
