.setcpu "65816"
.segment "CODE"
.org $124C
map_control_0c124c:
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
