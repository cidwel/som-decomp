.setcpu "65816"
.segment "CODE"
.org $A67E
map_control_0ea67e:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
