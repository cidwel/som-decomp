; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AF99
boss_lz_controls_dbaf99:
    ; backreference count 3, distance 401
    .byte $81, $90
    ; literal count 37; subsequent asset bytes excluded
    .byte $24
