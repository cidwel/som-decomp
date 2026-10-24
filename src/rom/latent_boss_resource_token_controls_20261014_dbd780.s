; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D780
boss_lz_controls_dbd780:
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 3, distance 934
    .byte $83, $A5
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
