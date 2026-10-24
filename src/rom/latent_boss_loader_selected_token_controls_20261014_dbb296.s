; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B296
boss_lz_controls_dbb296:
    ; backreference count 5, distance 425
    .byte $89, $A8
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
