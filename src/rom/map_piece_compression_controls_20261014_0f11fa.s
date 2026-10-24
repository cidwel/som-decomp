.setcpu "65816"
.segment "CODE"
.org $11FA
map_control_0f11fa:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $D5 ; same-value copy count/distance
