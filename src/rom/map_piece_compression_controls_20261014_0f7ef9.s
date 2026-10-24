.setcpu "65816"
.segment "CODE"
.org $7EF9
map_control_0f7ef9:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E1 ; previous-row copy count
