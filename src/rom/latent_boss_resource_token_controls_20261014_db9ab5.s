; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9AB5
boss_lz_controls_db9ab5:
    ; backreference count 3, distance 24
    .byte $80, $17
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
