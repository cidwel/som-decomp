.setcpu "65816"
.segment "CODE"
.org $9493
map_control_0d9493:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
