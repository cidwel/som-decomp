; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $94C9
boss_lz_controls_db94c9:
    ; backreference count 3, distance 31
    .byte $80, $1E
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
