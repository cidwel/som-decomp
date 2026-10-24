; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBD0
boss_lz_controls_dbbbd0:
    ; backreference count 4, distance 258
    .byte $85, $01
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
