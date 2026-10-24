; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED08
boss_lz_controls_daed08:
    ; backreference count 5, distance 172
    .byte $A0, $AB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
