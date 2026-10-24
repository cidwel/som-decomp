; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A0BD
boss_lz_controls_dba0bd:
    ; backreference count 3, distance 1131
    .byte $84, $6A
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
