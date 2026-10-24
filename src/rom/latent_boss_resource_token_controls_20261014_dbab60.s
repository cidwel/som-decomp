; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AB60
boss_lz_controls_dbab60:
    ; backreference count 3, distance 563
    .byte $82, $32
    ; literal count 31; subsequent asset bytes excluded
    .byte $1E
