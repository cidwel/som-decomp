.setcpu "65816"
.segment "CODE"
.org $7D5C
map_control_0d7d5c:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
