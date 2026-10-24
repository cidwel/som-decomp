.setcpu "65816"
.segment "CODE"
.org $3C3B
map_control_0e3c3b:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
