.setcpu "65816"
.segment "CODE"
.org $99B7
map_control_0e99b7:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
