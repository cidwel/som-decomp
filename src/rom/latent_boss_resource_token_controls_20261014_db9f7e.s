; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F7E
boss_lz_controls_db9f7e:
    ; backreference count 3, distance 21
    .byte $80, $14
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
