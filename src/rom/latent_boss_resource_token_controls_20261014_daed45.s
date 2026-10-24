; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED45
boss_lz_controls_daed45:
    ; backreference count 8, distance 16
    .byte $D0, $0F
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
