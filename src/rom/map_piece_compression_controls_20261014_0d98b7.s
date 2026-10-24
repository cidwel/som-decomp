.setcpu "65816"
.segment "CODE"
.org $98B7
map_control_0d98b7:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E2 ; previous-row copy count
