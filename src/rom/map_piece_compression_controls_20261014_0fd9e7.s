.setcpu "65816"
.segment "CODE"
.org $D9E7
map_control_0fd9e7:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
