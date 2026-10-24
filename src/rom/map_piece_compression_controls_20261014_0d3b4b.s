.setcpu "65816"
.segment "CODE"
.org $3B4B
map_control_0d3b4b:
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
