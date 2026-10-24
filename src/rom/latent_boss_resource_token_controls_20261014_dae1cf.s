; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1CF
boss_lz_controls_dae1cf:
    ; backreference count 3, distance 272
    .byte $81, $0F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
