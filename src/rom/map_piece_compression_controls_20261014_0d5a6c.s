.setcpu "65816"
.segment "CODE"
.org $5A6C
map_control_0d5a6c:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E2 ; previous-row copy count
