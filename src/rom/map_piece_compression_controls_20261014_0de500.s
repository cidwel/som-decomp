.setcpu "65816"
.segment "CODE"
.org $E500
map_control_0de500:
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
