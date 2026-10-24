; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED0C
boss_lz_controls_daed0c:
    ; backreference count 7, distance 166
    .byte $C0, $A5
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
