.setcpu "65816"
.segment "CODE"
.org $7580
map_control_0f7580:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C9 ; same-value copy count/distance
