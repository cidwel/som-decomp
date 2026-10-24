; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B727
boss_lz_controls_dbb727:
    ; backreference count 4, distance 464
    .byte $85, $CF
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
