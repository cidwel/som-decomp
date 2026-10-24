.setcpu "65816"
.segment "CODE"
.org $A7C7
map_control_0ea7c7:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
