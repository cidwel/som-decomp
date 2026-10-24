.setcpu "65816"
.segment "CODE"
.org $4102
map_control_0e4102:
    .byte $CB ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
