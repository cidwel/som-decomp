; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B025
boss_lz_controls_dbb025:
    ; backreference count 7, distance 507
    .byte $91, $FA
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
