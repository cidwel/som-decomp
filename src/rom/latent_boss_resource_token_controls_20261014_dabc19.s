; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC19
boss_lz_controls_dabc19:
    ; backreference count 3, distance 42
    .byte $80, $29
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
