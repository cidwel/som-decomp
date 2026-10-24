.setcpu "65816"
.segment "CODE"
.org $5B60
map_control_0d5b60:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
