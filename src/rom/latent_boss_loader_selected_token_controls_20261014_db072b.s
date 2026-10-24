; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $072B
boss_lz_controls_db072b:
    ; backreference count 7, distance 17
    .byte $C0, $10
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
