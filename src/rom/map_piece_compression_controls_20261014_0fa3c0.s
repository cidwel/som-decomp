.setcpu "65816"
.segment "CODE"
.org $A3C0
map_control_0fa3c0:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
