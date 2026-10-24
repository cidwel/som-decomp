.setcpu "65816"
.segment "CODE"
.org $7148
map_control_0f7148:
    .byte $CD ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
