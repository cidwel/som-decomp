; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ECAB
boss_lz_controls_daecab:
    ; backreference count 3, distance 73
    .byte $80, $48
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
