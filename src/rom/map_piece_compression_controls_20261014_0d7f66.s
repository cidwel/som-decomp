.setcpu "65816"
.segment "CODE"
.org $7F66
map_control_0d7f66:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
