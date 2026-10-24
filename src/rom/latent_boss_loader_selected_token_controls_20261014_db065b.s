; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $065B
boss_lz_controls_db065b:
    ; backreference count 4, distance 1535
    .byte $95, $FE
    ; backreference count 5, distance 1009
    .byte $A3, $F0
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
