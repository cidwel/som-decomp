; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E2AB
boss_lz_controls_dae2ab:
    ; backreference count 3, distance 168
    .byte $80, $A7
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
