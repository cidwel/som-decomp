.setcpu "65816"
.segment "CODE"
.org $89BC
map_control_0e89bc:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
