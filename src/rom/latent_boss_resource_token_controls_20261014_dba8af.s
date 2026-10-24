; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A8AF
boss_lz_controls_dba8af:
    ; backreference count 3, distance 429
    .byte $81, $AC
    ; backreference count 11, distance 493
    .byte $A1, $EC
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
