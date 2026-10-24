.setcpu "65816"
.segment "CODE"
.org $744C
map_control_0d744c:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E6 ; previous-row copy count
