.setcpu "65816"
.segment "CODE"
.org $8319
map_control_0e8319:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
