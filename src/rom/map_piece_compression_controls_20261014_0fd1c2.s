.setcpu "65816"
.segment "CODE"
.org $D1C2
map_control_0fd1c2:
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
