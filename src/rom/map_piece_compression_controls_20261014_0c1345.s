.setcpu "65816"
.segment "CODE"
.org $1345
map_control_0c1345:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
