; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC71
boss_lz_controls_dbac71:
    ; backreference count 3, distance 315
    .byte $81, $3A
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
