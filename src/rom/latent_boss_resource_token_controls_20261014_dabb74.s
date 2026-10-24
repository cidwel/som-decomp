; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB74
boss_lz_controls_dabb74:
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
