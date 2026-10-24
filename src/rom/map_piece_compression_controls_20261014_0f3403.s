.setcpu "65816"
.segment "CODE"
.org $3403
map_control_0f3403:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
