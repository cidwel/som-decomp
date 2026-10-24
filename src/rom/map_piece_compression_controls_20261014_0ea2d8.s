.setcpu "65816"
.segment "CODE"
.org $A2D8
map_control_0ea2d8:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
