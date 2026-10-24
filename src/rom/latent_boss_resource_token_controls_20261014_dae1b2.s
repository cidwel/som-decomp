; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1B2
boss_lz_controls_dae1b2:
    ; backreference count 3, distance 26
    .byte $80, $19
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
