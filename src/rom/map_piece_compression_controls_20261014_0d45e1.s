.setcpu "65816"
.segment "CODE"
.org $45E1
map_control_0d45e1:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E2 ; previous-row copy count
