.setcpu "65816"
.segment "CODE"
.org $4236
map_control_0d4236:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
