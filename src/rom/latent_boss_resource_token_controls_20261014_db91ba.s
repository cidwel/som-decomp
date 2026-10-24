; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $91BA
boss_lz_controls_db91ba:
    ; backreference count 3, distance 512
    .byte $81, $FF
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
