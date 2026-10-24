; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $948D
boss_lz_controls_db948d:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
