.setcpu "65816"
.segment "CODE"
.org $112E
map_control_0f112e:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
