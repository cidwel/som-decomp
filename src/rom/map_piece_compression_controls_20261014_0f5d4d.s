.setcpu "65816"
.segment "CODE"
.org $5D4D
map_control_0f5d4d:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
