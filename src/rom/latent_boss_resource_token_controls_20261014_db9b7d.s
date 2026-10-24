; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9B7D
boss_lz_controls_db9b7d:
    ; backreference count 5, distance 9
    .byte $90, $08
    ; backreference count 8, distance 1
    .byte $A8, $00
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
