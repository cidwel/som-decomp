.setcpu "65816"
.segment "CODE"
.org $E600
map_control_0de600:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
