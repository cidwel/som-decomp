; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBCE
boss_lz_controls_dabbce:
    ; backreference count 3, distance 616
    .byte $82, $67
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
