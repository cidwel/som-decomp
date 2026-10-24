; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3DD
boss_lz_controls_dba3dd:
    ; backreference count 3, distance 1040
    .byte $84, $0F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
