.setcpu "65816"
.segment "CODE"
.org $E49C
map_control_0de49c:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
