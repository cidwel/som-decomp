.setcpu "65816"
.segment "CODE"
.org $7676
map_control_0d7676:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
