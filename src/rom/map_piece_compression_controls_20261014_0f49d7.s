.setcpu "65816"
.segment "CODE"
.org $49D7
map_control_0f49d7:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E3 ; previous-row copy count
