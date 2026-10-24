.setcpu "65816"
.segment "CODE"
.org $49FE
map_control_0c49fe:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
