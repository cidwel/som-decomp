.setcpu "65816"
.segment "CODE"
.org $B636
map_control_0db636:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
