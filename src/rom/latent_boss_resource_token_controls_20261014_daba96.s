; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA96
boss_lz_controls_daba96:
    ; backreference count 7, distance 105
    .byte $90, $68
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
