.setcpu "65816"
.segment "CODE"
.org $A5B4
map_control_0fa5b4:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
