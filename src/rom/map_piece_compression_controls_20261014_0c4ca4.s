.setcpu "65816"
.segment "CODE"
.org $4CA4
map_control_0c4ca4:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
