; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0203
boss_lz_controls_db0203:
    ; backreference count 4, distance 606
    .byte $92, $5D
    ; backreference count 3, distance 80
    .byte $80, $4F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
