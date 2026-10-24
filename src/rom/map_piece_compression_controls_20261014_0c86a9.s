.setcpu "65816"
.segment "CODE"
.org $86A9
map_control_0c86a9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
