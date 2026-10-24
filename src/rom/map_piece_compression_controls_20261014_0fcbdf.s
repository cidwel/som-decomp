.setcpu "65816"
.segment "CODE"
.org $CBDF
map_control_0fcbdf:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
