.setcpu "65816"
.segment "CODE"
.org $224F
map_control_0f224f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
