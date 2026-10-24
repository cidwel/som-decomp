; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BD0D
boss_lz_controls_dbbd0d:
    ; backreference count 4, distance 182
    .byte $88, $B5
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
