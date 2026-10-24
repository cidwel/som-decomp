.setcpu "65816"
.segment "CODE"
.org $5FD7
map_control_0d5fd7:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
