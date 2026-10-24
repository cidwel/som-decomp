.setcpu "65816"
.segment "CODE"
.org $AF3A
map_control_0daf3a:
    .byte $C9 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
