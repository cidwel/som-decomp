; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A689
boss_lz_controls_dba689:
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
