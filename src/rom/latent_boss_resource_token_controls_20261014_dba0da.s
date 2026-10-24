; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A0DA
boss_lz_controls_dba0da:
    ; backreference count 5, distance 14
    .byte $90, $0D
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
