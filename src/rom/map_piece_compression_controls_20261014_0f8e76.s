.setcpu "65816"
.segment "CODE"
.org $8E76
map_control_0f8e76:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
