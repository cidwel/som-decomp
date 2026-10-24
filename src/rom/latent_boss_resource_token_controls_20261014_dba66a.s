; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A66A
boss_lz_controls_dba66a:
    ; backreference count 3, distance 159
    .byte $80, $9E
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
