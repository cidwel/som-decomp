.setcpu "65816"
.segment "CODE"
.org $3992
map_control_0d3992:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E6 ; previous-row copy count
