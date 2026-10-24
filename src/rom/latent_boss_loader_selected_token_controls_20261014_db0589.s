; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0589
boss_lz_controls_db0589:
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; backreference count 3, distance 93
    .byte $80, $5C
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
