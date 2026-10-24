; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF27
boss_lz_controls_dadf27:
    ; backreference count 4, distance 143
    .byte $88, $8E
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
