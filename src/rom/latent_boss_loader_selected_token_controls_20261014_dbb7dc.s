; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7DC
boss_lz_controls_dbb7dc:
    ; backreference count 4, distance 54
    .byte $84, $35
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
