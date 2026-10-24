; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB3B
boss_lz_controls_dabb3b:
    ; backreference count 3, distance 31
    .byte $80, $1E
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
