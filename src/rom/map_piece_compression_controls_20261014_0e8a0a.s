.setcpu "65816"
.segment "CODE"
.org $8A0A
map_control_0e8a0a:
    .byte $EA ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
