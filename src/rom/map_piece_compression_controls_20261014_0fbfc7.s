.setcpu "65816"
.segment "CODE"
.org $BFC7
map_control_0fbfc7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
