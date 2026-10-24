; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFA6
boss_lz_controls_dacfa6:
    ; backreference count 3, distance 19
    .byte $80, $12
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
