; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E29F
boss_lz_controls_dae29f:
    ; backreference count 4, distance 346
    .byte $89, $59
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
