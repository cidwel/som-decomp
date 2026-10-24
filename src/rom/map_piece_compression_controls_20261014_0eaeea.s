.setcpu "65816"
.segment "CODE"
.org $AEEA
map_control_0eaeea:
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
