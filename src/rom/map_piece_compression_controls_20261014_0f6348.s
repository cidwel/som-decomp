.setcpu "65816"
.segment "CODE"
.org $6348
map_control_0f6348:
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E1 ; previous-row copy count
