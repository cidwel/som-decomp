; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE41
boss_lz_controls_dbbe41:
    ; backreference count 3, distance 59
    .byte $80, $3A
    ; literal count 29; subsequent asset bytes excluded
    .byte $1C
