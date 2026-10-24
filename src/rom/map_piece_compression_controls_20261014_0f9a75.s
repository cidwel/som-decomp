.setcpu "65816"
.segment "CODE"
.org $9A75
map_control_0f9a75:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
