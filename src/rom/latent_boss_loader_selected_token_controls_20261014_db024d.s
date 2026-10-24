; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $024D
boss_lz_controls_db024d:
    ; backreference count 3, distance 400
    .byte $81, $8F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
