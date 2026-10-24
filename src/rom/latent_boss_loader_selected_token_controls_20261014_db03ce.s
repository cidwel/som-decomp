; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03CE
boss_lz_controls_db03ce:
    ; backreference count 9, distance 18
    .byte $E0, $11
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
