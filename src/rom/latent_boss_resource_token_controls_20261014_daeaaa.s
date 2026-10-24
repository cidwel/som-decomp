; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EAAA
boss_lz_controls_daeaaa:
    ; backreference count 3, distance 267
    .byte $81, $0A
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
