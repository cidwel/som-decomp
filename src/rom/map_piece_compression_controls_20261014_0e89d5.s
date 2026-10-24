.setcpu "65816"
.segment "CODE"
.org $89D5
map_control_0e89d5:
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
