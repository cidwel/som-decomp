; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED25
boss_lz_controls_daed25:
    ; backreference count 3, distance 146
    .byte $80, $91
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
