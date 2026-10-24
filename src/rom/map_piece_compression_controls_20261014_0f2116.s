.setcpu "65816"
.segment "CODE"
.org $2116
map_control_0f2116:
    .byte $CB ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E3 ; previous-row copy count
