.setcpu "65816"
.segment "CODE"
.org $5894
map_control_0f5894:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
