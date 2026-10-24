.setcpu "65816"
.segment "CODE"
.org $1CE2
map_control_0e1ce2:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
