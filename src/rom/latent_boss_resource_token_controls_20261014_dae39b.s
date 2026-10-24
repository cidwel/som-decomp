; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E39B
boss_lz_controls_dae39b:
    ; backreference count 4, distance 898
    .byte $8B, $81
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
