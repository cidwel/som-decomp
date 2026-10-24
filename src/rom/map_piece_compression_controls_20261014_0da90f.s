.setcpu "65816"
.segment "CODE"
.org $A90F
map_control_0da90f:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E1 ; previous-row copy count
