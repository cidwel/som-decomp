.setcpu "65816"
.segment "CODE"
.org $DF82
map_control_0fdf82:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
