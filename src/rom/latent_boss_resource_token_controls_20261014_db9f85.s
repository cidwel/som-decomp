; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F85
boss_lz_controls_db9f85:
    ; backreference count 3, distance 789
    .byte $83, $14
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
