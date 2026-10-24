.setcpu "65816"
.segment "CODE"
.org $44F5
map_control_0f44f5:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
