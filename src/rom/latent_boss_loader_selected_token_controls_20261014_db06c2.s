; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06C2
boss_lz_controls_db06c2:
    ; backreference count 3, distance 5
    .byte $80, $04
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
