; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $921D
boss_lz_controls_db921d:
    ; backreference count 3, distance 105
    .byte $80, $68
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
