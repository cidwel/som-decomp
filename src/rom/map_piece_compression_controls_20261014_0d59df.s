.setcpu "65816"
.segment "CODE"
.org $59DF
map_control_0d59df:
    .byte $C9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
