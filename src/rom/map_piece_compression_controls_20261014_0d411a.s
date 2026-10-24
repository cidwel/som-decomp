.setcpu "65816"
.segment "CODE"
.org $411A
map_control_0d411a:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
