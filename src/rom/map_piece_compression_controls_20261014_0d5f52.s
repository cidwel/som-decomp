.setcpu "65816"
.segment "CODE"
.org $5F52
map_control_0d5f52:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
