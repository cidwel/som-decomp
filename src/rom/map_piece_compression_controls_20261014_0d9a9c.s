.setcpu "65816"
.segment "CODE"
.org $9A9C
map_control_0d9a9c:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
