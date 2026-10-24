; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED4B
boss_lz_controls_daed4b:
    ; backreference count 5, distance 1295
    .byte $A5, $0E
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
