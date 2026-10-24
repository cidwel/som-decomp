.setcpu "65816"
.segment "CODE"
.org $9659
map_control_0e9659:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
