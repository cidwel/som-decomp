.setcpu "65816"
.segment "CODE"
.org $46E5
map_control_0d46e5:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
