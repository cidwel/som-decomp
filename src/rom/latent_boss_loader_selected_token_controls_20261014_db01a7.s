; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01A7
boss_lz_controls_db01a7:
    ; backreference count 4, distance 120
    .byte $90, $77
    ; backreference count 3, distance 248
    .byte $80, $F7
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
