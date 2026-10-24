; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F1A0
boss_lz_controls_daf1a0:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 98; subsequent asset bytes excluded
    .byte $61
