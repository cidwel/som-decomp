.setcpu "65816"
.segment "CODE"
.org $9000
map_control_0d9000:
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
