.setcpu "65816"
.segment "CODE"
.org $A3B2
map_control_0fa3b2:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E2 ; previous-row copy count
