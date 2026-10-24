.setcpu "65816"
.segment "CODE"
.org $25B1
map_control_0e25b1:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
