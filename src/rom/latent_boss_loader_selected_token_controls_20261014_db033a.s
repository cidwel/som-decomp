; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $033A
boss_lz_controls_db033a:
    ; backreference count 4, distance 58
    .byte $90, $39
    ; backreference count 4, distance 140
    .byte $90, $8B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
