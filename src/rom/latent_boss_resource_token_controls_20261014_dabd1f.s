; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BD1F
boss_lz_controls_dabd1f:
    ; backreference count 3, distance 29
    .byte $80, $1C
    ; literal count 89; subsequent asset bytes excluded
    .byte $58
