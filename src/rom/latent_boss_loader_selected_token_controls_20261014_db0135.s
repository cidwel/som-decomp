; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0135
boss_lz_controls_db0135:
    ; backreference count 4, distance 45
    .byte $90, $2C
    ; backreference count 3, distance 46
    .byte $80, $2D
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
