; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BE4
boss_lz_controls_db0be4:
    ; compression selector
    .byte $04
