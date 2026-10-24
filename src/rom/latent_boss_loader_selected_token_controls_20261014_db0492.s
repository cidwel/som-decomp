; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0492
boss_lz_controls_db0492:
    ; backreference count 4, distance 1051
    .byte $94, $1A
    ; backreference count 5, distance 507
    .byte $A1, $FA
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
