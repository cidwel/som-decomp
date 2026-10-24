.setcpu "65816"
.segment "CODE"
.org $49D8
map_control_0c49d8:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
