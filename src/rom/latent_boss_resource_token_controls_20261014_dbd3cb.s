; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D3CB
boss_lz_controls_dbd3cb:
    ; backreference count 3, distance 67
    .byte $80, $42
    ; literal count 19; subsequent asset bytes excluded
    .byte $12
