.setcpu "65816"
.segment "CODE"
.org $45C7
map_control_0d45c7:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E2 ; previous-row copy count
