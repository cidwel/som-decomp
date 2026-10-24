; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFC0
boss_lz_controls_dadfc0:
    ; backreference count 4, distance 22
    .byte $88, $15
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
