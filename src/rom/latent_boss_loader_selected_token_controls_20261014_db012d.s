; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $012D
boss_lz_controls_db012d:
    ; backreference count 4, distance 119
    .byte $90, $76
    ; backreference count 3, distance 238
    .byte $80, $ED
    ; backreference count 3, distance 229
    .byte $80, $E4
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
