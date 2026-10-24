; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A190
boss_lz_controls_dba190:
    ; backreference count 3, distance 1046
    .byte $84, $15
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
