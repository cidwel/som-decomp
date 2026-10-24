.setcpu "65816"
.segment "CODE"
.org $5A67
map_control_0f5a67:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
