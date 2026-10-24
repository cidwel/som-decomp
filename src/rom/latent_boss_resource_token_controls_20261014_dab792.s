; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B792
boss_lz_controls_dab792:
    ; backreference count 4, distance 14
    .byte $84, $0D
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
