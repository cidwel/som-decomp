.setcpu "65816"
.segment "CODE"
.org $8185
map_control_0f8185:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
