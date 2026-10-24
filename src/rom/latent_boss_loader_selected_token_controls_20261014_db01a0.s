; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01A0
boss_lz_controls_db01a0:
    ; backreference count 10, distance 221
    .byte $F0, $DC
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
