.setcpu "65816"
.segment "CODE"
.org $AACE
map_control_0daace:
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
