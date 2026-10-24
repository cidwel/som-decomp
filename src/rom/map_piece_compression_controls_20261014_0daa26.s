.setcpu "65816"
.segment "CODE"
.org $AA26
map_control_0daa26:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
