; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEBD
boss_lz_controls_dbcebd:
    ; backreference count 3, distance 803
    .byte $83, $22
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
