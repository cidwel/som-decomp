.setcpu "65816"
.segment "CODE"
.org $0081
map_control_0e0081:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
