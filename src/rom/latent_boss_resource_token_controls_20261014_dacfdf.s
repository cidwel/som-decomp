; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFDF
boss_lz_controls_dacfdf:
    ; backreference count 3, distance 81
    .byte $80, $50
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
