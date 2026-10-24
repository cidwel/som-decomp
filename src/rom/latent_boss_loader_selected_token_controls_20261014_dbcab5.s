; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAB5
boss_lz_controls_dbcab5:
    ; backreference count 3, distance 1041
    .byte $84, $10
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
