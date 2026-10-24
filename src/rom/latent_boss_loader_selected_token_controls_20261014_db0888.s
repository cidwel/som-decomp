; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0888
boss_lz_controls_db0888:
    ; backreference count 5, distance 1377
    .byte $A5, $60
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
