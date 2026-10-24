.setcpu "65816"
.segment "CODE"
.org $6C4D
map_control_0f6c4d:
    .byte $D1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $F2 ; progressive-copy count
