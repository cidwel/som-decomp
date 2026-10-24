; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A653
boss_lz_controls_dba653:
    ; backreference count 53, distance 1
    .byte $E4, $00
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
