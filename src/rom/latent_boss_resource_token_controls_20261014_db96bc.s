; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $96BC
boss_lz_controls_db96bc:
    ; backreference count 3, distance 51
    .byte $80, $32
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
