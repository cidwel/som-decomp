; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A27C
boss_lz_controls_dba27c:
    ; backreference count 3, distance 616
    .byte $82, $67
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
