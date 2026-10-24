; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7E8
boss_lz_controls_dab7e8:
    ; backreference count 4, distance 26
    .byte $84, $19
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
