; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $90A2
boss_lz_controls_db90a2:
    ; backreference count 5, distance 331
    .byte $A1, $4A
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
