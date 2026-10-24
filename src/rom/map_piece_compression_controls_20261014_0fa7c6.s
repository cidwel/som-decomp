.setcpu "65816"
.segment "CODE"
.org $A7C6
map_control_0fa7c6:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E2 ; previous-row copy count
