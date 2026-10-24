; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7C3
boss_lz_controls_dbb7c3:
    ; backreference count 3, distance 822
    .byte $83, $35
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
