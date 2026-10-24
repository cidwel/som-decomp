; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05A2
boss_lz_controls_db05a2:
    ; backreference count 5, distance 1276
    .byte $A4, $FB
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
