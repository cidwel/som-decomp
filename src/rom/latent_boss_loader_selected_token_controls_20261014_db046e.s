; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $046E
boss_lz_controls_db046e:
    ; backreference count 4, distance 423
    .byte $91, $A6
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
