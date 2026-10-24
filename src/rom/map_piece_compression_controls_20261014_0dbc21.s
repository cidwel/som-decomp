.setcpu "65816"
.segment "CODE"
.org $BC21
map_control_0dbc21:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C6 ; same-value copy count/distance
