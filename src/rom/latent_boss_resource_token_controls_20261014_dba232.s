; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A232
boss_lz_controls_dba232:
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
