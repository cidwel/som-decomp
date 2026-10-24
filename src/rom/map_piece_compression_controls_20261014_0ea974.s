.setcpu "65816"
.segment "CODE"
.org $A974
map_control_0ea974:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
