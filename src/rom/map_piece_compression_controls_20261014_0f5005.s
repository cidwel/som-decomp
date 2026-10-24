.setcpu "65816"
.segment "CODE"
.org $5005
map_control_0f5005:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
