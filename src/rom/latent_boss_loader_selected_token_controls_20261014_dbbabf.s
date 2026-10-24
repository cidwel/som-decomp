; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BABF
boss_lz_controls_dbbabf:
    ; backreference count 3, distance 325
    .byte $81, $44
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
