.setcpu "65816"
.segment "CODE"
.org $7C08
map_control_0c7c08:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E5 ; previous-row copy count
