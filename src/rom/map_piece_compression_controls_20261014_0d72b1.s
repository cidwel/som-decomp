.setcpu "65816"
.segment "CODE"
.org $72B1
map_control_0d72b1:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
