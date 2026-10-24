; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F91
boss_lz_controls_db9f91:
    ; backreference count 3, distance 19
    .byte $80, $12
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
