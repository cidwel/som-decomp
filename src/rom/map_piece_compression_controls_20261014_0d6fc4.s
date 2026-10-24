.setcpu "65816"
.segment "CODE"
.org $6FC4
map_control_0d6fc4:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
