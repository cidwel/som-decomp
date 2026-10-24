; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEFA
boss_lz_controls_dacefa:
    ; literal count 28; subsequent asset bytes excluded
    .byte $1B
