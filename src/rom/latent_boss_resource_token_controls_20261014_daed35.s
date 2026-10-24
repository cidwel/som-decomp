; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED35
boss_lz_controls_daed35:
    ; backreference count 5, distance 1415
    .byte $A5, $86
    ; backreference count 4, distance 65
    .byte $90, $40
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
