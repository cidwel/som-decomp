.setcpu "65816"
.segment "CODE"
.org $5F6F
map_control_0d5f6f:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
