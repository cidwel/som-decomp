.setcpu "65816"
.segment "CODE"
.org $1DBD
map_control_0d1dbd:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
