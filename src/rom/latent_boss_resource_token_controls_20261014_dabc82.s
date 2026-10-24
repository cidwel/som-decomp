; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC82
boss_lz_controls_dabc82:
    ; backreference count 3, distance 39
    .byte $80, $26
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
