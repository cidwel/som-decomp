; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A554
boss_lz_controls_dba554:
    ; backreference count 4, distance 21
    .byte $82, $14
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
