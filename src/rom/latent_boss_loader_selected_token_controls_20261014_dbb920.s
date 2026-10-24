; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B920
boss_lz_controls_dbb920:
    ; backreference count 3, distance 307
    .byte $81, $32
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
