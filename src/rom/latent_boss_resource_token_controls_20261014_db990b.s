; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $990B
boss_lz_controls_db990b:
    ; backreference count 3, distance 91
    .byte $80, $5A
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A
