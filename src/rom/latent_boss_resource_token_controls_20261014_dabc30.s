; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC30
boss_lz_controls_dabc30:
    ; backreference count 3, distance 53
    .byte $80, $34
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
