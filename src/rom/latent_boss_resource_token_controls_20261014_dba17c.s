; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A17C
boss_lz_controls_dba17c:
    ; backreference count 7, distance 1140
    .byte $A4, $73
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
