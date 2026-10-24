; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $031E
boss_lz_controls_db031e:
    ; backreference count 3, distance 70
    .byte $80, $45
    ; backreference count 4, distance 256
    .byte $90, $FF
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
