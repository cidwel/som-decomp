; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $99F1
boss_lz_controls_db99f1:
    ; backreference count 3, distance 2480
    .byte $89, $AF
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
