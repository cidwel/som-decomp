.setcpu "65816"
.segment "CODE"
.org $CEE4
map_control_0dcee4:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E1 ; previous-row copy count
