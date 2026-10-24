; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE03
boss_lz_controls_dabe03:
    ; backreference count 4, distance 47
    .byte $84, $2E
    ; literal count 22; subsequent asset bytes excluded
    .byte $15
