; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F2E0
boss_lz_controls_daf2e0:
    ; backreference count 3, distance 1372
    .byte $85, $5B
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
