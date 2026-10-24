.setcpu "65816"
.segment "CODE"
.org $1A5D
map_control_0e1a5d:
    .byte $CA ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E7 ; previous-row copy count
