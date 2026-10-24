; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCE6
boss_lz_controls_dbbce6:
    ; backreference count 4, distance 20
    .byte $88, $13
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
