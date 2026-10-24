; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D123
boss_lz_controls_dbd123:
    ; backreference count 3, distance 1528
    .byte $85, $F7
    ; literal count 91; subsequent asset bytes excluded
    .byte $5A
