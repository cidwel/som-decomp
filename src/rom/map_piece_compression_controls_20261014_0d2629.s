.setcpu "65816"
.segment "CODE"
.org $2629
map_control_0d2629:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E6 ; previous-row copy count
