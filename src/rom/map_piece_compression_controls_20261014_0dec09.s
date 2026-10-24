.setcpu "65816"
.segment "CODE"
.org $EC09
map_control_0dec09:
    .byte $E3 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
