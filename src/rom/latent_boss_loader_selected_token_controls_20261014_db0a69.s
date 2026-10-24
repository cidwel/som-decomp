; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A69
boss_lz_controls_db0a69:
    ; backreference count 5, distance 3138
    .byte $AC, $41
    ; backreference count 3, distance 624
    .byte $82, $6F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
