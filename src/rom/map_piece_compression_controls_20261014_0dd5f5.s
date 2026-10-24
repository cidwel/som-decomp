.setcpu "65816"
.segment "CODE"
.org $D5F5
map_control_0dd5f5:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
