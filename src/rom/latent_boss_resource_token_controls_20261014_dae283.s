; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E283
boss_lz_controls_dae283:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
