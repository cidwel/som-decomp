; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0890
boss_lz_controls_db0890:
    ; backreference count 4, distance 1385
    .byte $95, $68
    ; backreference count 4, distance 7
    .byte $90, $06
    ; backreference count 3, distance 2083
    .byte $88, $22
    ; backreference count 5, distance 1383
    .byte $A5, $66
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
