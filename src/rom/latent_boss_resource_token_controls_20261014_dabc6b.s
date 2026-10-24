; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC6B
boss_lz_controls_dabc6b:
    ; backreference count 3, distance 4
    .byte $80, $03
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
