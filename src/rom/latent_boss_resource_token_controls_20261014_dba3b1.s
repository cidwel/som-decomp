; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3B1
boss_lz_controls_dba3b1:
    ; backreference count 3, distance 620
    .byte $82, $6B
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
