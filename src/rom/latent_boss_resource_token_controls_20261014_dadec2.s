; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DEC2
boss_lz_controls_dadec2:
    ; backreference count 3, distance 374
    .byte $81, $75
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
