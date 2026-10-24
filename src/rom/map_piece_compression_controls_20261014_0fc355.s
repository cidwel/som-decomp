.setcpu "65816"
.segment "CODE"
.org $C355
map_control_0fc355:
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
