; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9884
boss_lz_controls_db9884:
    ; backreference count 3, distance 54
    .byte $80, $35
    ; backreference count 4, distance 53
    .byte $90, $34
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
