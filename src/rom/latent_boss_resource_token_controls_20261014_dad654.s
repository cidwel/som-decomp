; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D654
boss_lz_controls_dad654:
    ; backreference count 3, distance 289
    .byte $81, $20
    ; backreference count 5, distance 1455
    .byte $95, $AE
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
