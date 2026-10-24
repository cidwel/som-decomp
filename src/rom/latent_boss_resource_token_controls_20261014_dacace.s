; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CACE
boss_lz_controls_dacace:
    ; backreference count 3, distance 1265
    .byte $84, $F0
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
