.setcpu "65816"
.segment "CODE"
.org $35FC
map_control_0d35fc:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $CD ; same-value copy count/distance
