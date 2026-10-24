; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $050E
boss_lz_controls_db050e:
    ; backreference count 4, distance 1218
    .byte $94, $C1
    ; backreference count 3, distance 8
    .byte $80, $07
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
