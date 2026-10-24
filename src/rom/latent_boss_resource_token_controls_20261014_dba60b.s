; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A60B
boss_lz_controls_dba60b:
    ; backreference count 3, distance 120
    .byte $80, $77
    ; literal count 35; subsequent asset bytes excluded
    .byte $22
