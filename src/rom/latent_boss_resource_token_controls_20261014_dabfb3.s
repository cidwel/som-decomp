; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFB3
boss_lz_controls_dabfb3:
    ; backreference count 3, distance 39
    .byte $80, $26
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
