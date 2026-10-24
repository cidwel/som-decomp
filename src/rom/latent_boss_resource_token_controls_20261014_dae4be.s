; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E4BE
boss_lz_controls_dae4be:
    ; backreference count 9, distance 972
    .byte $B3, $CB
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
