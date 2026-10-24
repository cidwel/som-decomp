.setcpu "65816"
.segment "CODE"
.org $800C
map_control_0d800c:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E5 ; previous-row copy count
