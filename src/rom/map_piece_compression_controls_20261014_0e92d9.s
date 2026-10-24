.setcpu "65816"
.segment "CODE"
.org $92D9
map_control_0e92d9:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
