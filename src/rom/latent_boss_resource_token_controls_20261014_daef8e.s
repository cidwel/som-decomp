; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EF8E
boss_lz_controls_daef8e:
    ; backreference count 4, distance 2380
    .byte $99, $4B
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
