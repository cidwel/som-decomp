.setcpu "65816"
.segment "CODE"
.org $102C
map_control_0e102c:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
