; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A5AA
boss_lz_controls_dba5aa:
    ; backreference count 3, distance 57
    .byte $80, $38
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
