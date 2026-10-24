.setcpu "65816"
.segment "CODE"
.org $7E28
map_control_0f7e28:
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
