.setcpu "65816"
.segment "CODE"
.org $8A83
map_control_0e8a83:
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
