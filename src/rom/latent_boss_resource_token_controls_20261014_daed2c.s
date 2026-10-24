; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED2C
boss_lz_controls_daed2c:
    ; backreference count 3, distance 1231
    .byte $84, $CE
    ; backreference count 3, distance 90
    .byte $80, $59
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
