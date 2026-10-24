.setcpu "65816"
.segment "CODE"
.org $630B
map_control_0d630b:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
