.setcpu "65816"
.segment "CODE"
.org $8A22
map_control_0e8a22:
    .byte $EA ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
