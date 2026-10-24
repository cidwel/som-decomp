; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A485
boss_lz_controls_dba485:
    ; backreference count 5, distance 13
    .byte $84, $0C
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
