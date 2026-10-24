.setcpu "65816"
.segment "CODE"
.org $89A5
map_control_0e89a5:
    .byte $EA ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
