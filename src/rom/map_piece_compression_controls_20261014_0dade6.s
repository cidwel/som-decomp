.setcpu "65816"
.segment "CODE"
.org $ADE6
map_control_0dade6:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E7 ; previous-row copy count
