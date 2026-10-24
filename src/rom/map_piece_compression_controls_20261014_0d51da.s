.setcpu "65816"
.segment "CODE"
.org $51DA
map_control_0d51da:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
