; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02FD
boss_lz_controls_db02fd:
    ; backreference count 7, distance 187
    .byte $C0, $BA
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
