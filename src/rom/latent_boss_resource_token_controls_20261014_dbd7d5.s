; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7D5
boss_lz_controls_dbd7d5:
    ; backreference count 3, distance 27
    .byte $80, $1A
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
