; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F3F
boss_lz_controls_db9f3f:
    ; backreference count 8, distance 126
    .byte $A8, $7D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
