; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9C54
boss_lz_controls_db9c54:
    ; backreference count 4, distance 252
    .byte $88, $FB
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
