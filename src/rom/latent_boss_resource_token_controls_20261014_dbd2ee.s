; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2EE
boss_lz_controls_dbd2ee:
    ; backreference count 3, distance 26
    .byte $80, $19
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
