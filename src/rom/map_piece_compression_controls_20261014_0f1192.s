.setcpu "65816"
.segment "CODE"
.org $1192
map_control_0f1192:
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
