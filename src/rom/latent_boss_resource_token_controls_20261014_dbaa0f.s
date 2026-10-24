; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AA0F
boss_lz_controls_dbaa0f:
    ; backreference count 3, distance 914
    .byte $83, $91
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
