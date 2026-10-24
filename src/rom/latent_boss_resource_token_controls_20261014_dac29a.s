; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C29A
boss_lz_controls_dac29a:
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
