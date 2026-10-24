.setcpu "65816"
.segment "CODE"
.org $70B2
map_control_0d70b2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E4 ; previous-row copy count
