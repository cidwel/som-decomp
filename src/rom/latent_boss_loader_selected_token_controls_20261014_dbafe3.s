; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AFE3
boss_lz_controls_dbafe3:
    ; backreference count 3, distance 89
    .byte $80, $58
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
