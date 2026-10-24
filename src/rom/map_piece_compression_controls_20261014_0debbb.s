.setcpu "65816"
.segment "CODE"
.org $EBBB
map_control_0debbb:
    .byte $C3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
