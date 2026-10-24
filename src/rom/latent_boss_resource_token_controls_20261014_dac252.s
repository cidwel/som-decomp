; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C252
boss_lz_controls_dac252:
    ; backreference count 18, distance 448
    .byte $BD, $BF
    ; backreference count 3, distance 6
    .byte $80, $05
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 21, distance 1
    .byte $C8, $00
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
