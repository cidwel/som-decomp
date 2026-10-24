; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA81
boss_lz_controls_daba81:
    ; backreference count 5, distance 461
    .byte $89, $CC
    ; backreference count 9, distance 52
    .byte $98, $33
    ; backreference count 5, distance 459
    .byte $89, $CA
    ; backreference count 30, distance 50
    .byte $EC, $31
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
