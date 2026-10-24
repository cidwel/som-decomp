.setcpu "65816"
.segment "CODE"
.org $4CA4
map_control_0f4ca4:
    .byte $ED ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $E5 ; previous-row copy count
