.setcpu "65816"
.segment "CODE"
.org $9695
map_control_0e9695:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
