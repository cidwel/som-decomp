.setcpu "65816"
.segment "CODE"
.org $EF7F
map_control_0def7f:
    .byte $C9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
