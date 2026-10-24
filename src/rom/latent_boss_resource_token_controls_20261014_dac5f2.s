; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C5F2
boss_lz_controls_dac5f2:
    ; backreference count 4, distance 216
    .byte $88, $D7
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
