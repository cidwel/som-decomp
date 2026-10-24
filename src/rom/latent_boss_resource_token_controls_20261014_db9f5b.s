; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F5B
boss_lz_controls_db9f5b:
    ; backreference count 4, distance 6
    .byte $88, $05
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
