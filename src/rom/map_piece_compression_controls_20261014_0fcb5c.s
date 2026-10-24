.setcpu "65816"
.segment "CODE"
.org $CB5C
map_control_0fcb5c:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
