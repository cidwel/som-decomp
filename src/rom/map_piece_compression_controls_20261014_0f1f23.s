.setcpu "65816"
.segment "CODE"
.org $1F23
map_control_0f1f23:
    .byte $C3 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
