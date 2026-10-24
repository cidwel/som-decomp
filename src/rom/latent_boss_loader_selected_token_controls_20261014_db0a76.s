; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A76
boss_lz_controls_db0a76:
    ; backreference count 4, distance 1364
    .byte $95, $53
    ; backreference count 8, distance 1472
    .byte $D5, $BF
    ; backreference count 4, distance 1
    .byte $90, $00
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
