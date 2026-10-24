; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E38B
boss_lz_controls_dae38b:
    ; backreference count 3, distance 26
    .byte $80, $19
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
