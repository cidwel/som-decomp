.setcpu "65816"
.segment "CODE"
.org $1CC4
map_control_0d1cc4:
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
