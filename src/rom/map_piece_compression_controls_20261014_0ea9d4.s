.setcpu "65816"
.segment "CODE"
.org $A9D4
map_control_0ea9d4:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
