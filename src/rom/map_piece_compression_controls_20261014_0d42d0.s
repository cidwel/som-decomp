.setcpu "65816"
.segment "CODE"
.org $42D0
map_control_0d42d0:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E2 ; previous-row copy count
