; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB57
boss_lz_controls_dbcb57:
    ; backreference count 4, distance 45
    .byte $90, $2C
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
