; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED8D
boss_lz_controls_daed8d:
    ; backreference count 3, distance 143
    .byte $80, $8E
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
