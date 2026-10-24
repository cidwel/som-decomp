; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E0F8
boss_lz_controls_dae0f8:
    ; backreference count 5, distance 1520
    .byte $95, $EF
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
