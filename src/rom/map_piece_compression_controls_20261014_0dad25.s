.setcpu "65816"
.segment "CODE"
.org $AD25
map_control_0dad25:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
