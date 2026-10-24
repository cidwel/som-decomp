; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D402
boss_lz_controls_dad402:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; backreference count 3, distance 775
    .byte $83, $06
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A
