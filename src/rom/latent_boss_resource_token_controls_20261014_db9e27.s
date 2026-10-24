; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9E27
boss_lz_controls_db9e27:
    ; backreference count 3, distance 80
    .byte $80, $4F
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
