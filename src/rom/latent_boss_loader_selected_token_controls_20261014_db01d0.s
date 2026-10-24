; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01D0
boss_lz_controls_db01d0:
    ; backreference count 3, distance 42
    .byte $80, $29
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
