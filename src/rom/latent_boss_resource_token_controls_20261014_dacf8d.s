; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF8D
boss_lz_controls_dacf8d:
    ; backreference count 6, distance 16
    .byte $98, $0F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
