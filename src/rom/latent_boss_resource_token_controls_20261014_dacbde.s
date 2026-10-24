; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBDE
boss_lz_controls_dacbde:
    ; backreference count 3, distance 618
    .byte $82, $69
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
