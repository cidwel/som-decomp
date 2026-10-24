; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6F1
boss_lz_controls_dbd6f1:
    ; backreference count 3, distance 967
    .byte $83, $C6
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
