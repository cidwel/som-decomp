.setcpu "65816"
.segment "CODE"
.org $0FD0
map_control_0c0fd0:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
