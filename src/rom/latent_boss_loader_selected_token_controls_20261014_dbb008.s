; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B008
boss_lz_controls_dbb008:
    ; backreference count 7, distance 146
    .byte $90, $91
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
