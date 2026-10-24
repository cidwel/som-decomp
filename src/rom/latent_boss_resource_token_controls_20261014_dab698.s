; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B698
boss_lz_controls_dab698:
    ; backreference count 13, distance 16
    .byte $A8, $0F
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
