; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB74
boss_lz_controls_dbbb74:
    ; backreference count 3, distance 5
    .byte $80, $04
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
