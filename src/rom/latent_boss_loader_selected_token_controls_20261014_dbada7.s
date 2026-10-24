; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ADA7
boss_lz_controls_dbada7:
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 91; subsequent asset bytes excluded
    .byte $5A
