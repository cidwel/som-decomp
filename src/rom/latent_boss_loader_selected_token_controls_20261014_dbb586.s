; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B586
boss_lz_controls_dbb586:
    ; backreference count 3, distance 337
    .byte $81, $50
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
