; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2DD
boss_lz_controls_dad2dd:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; backreference count 3, distance 60
    .byte $80, $3B
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
