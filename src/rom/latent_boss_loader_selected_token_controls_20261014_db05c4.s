; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05C4
boss_lz_controls_db05c4:
    ; backreference count 4, distance 105
    .byte $90, $68
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
