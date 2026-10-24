; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFB8
boss_lz_controls_dacfb8:
    ; backreference count 7, distance 8
    .byte $A0, $07
    ; literal count 36; subsequent asset bytes excluded
    .byte $23
