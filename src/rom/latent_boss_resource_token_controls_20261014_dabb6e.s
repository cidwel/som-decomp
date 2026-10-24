; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB6E
boss_lz_controls_dabb6e:
    ; backreference count 3, distance 22
    .byte $80, $15
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
