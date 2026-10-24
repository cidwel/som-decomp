; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D97A
boss_lz_controls_dad97a:
    ; backreference count 3, distance 56
    .byte $80, $37
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
