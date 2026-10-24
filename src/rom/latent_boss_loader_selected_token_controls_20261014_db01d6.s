; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01D6
boss_lz_controls_db01d6:
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
