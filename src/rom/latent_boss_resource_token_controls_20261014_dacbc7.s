; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBC7
boss_lz_controls_dacbc7:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
