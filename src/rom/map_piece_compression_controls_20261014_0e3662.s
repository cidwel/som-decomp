.setcpu "65816"
.segment "CODE"
.org $3662
map_control_0e3662:
    .byte $D7 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
