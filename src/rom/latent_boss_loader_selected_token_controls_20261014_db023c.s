; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $023C
boss_lz_controls_db023c:
    ; backreference count 6, distance 514
    .byte $B2, $01
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
