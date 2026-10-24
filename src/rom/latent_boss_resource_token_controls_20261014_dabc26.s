; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC26
boss_lz_controls_dabc26:
    ; backreference count 3, distance 34
    .byte $80, $21
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
