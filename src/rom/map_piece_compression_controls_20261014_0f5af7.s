.setcpu "65816"
.segment "CODE"
.org $5AF7
map_control_0f5af7:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
