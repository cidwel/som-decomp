.setcpu "65816"
.segment "CODE"
.org $A8E7
map_control_0da8e7:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
