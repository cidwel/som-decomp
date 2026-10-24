.setcpu "65816"
.segment "CODE"
.org $5F94
map_control_0f5f94:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E6 ; previous-row copy count
