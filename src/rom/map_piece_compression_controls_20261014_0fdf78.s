.setcpu "65816"
.segment "CODE"
.org $DF78
map_control_0fdf78:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
