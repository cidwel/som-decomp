.setcpu "65816"
.segment "CODE"
.org $AB97
map_control_0eab97:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
