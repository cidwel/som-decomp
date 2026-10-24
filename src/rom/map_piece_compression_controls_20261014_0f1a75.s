.setcpu "65816"
.segment "CODE"
.org $1A75
map_control_0f1a75:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $E2 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
