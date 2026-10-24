; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DCED
boss_lz_controls_dadced:
    ; backreference count 4, distance 14
    .byte $88, $0D
    ; literal count 122; subsequent asset bytes excluded
    .byte $79
