.setcpu "65816"
.segment "CODE"
.org $907C
map_control_0d907c:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
