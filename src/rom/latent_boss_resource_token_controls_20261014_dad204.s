; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D204
boss_lz_controls_dad204:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
