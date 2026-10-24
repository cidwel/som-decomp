; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07FE
boss_lz_controls_db07fe:
    ; backreference count 3, distance 604
    .byte $82, $5B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
