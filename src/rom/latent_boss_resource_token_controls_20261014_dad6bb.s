; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6BB
boss_lz_controls_dad6bb:
    ; backreference count 5, distance 63
    .byte $90, $3E
    ; literal count 63; subsequent asset bytes excluded
    .byte $3E
