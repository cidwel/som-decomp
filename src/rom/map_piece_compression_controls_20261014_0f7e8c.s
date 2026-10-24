.setcpu "65816"
.segment "CODE"
.org $7E8C
map_control_0f7e8c:
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
