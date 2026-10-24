; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF95
boss_lz_controls_dbcf95:
    ; backreference count 3, distance 835
    .byte $83, $42
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
