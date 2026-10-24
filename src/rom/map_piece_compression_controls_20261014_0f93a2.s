.setcpu "65816"
.segment "CODE"
.org $93A2
map_control_0f93a2:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
