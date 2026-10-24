; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D834
boss_lz_controls_dbd834:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
