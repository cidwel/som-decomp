; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDAA
boss_lz_controls_dacdaa:
    ; backreference count 3, distance 77
    .byte $80, $4C
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
