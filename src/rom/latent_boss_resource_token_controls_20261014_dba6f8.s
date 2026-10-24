; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A6F8
boss_lz_controls_dba6f8:
    ; backreference count 3, distance 90
    .byte $80, $59
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
