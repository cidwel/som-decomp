.setcpu "65816"
.segment "CODE"
.org $C567
map_control_0ec567:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
