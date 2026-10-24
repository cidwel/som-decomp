; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ECF3
boss_lz_controls_daecf3:
    ; backreference count 3, distance 61
    .byte $80, $3C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
