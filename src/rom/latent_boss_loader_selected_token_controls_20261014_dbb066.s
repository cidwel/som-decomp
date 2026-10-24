; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B066
boss_lz_controls_dbb066:
    ; backreference count 3, distance 139
    .byte $80, $8A
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
