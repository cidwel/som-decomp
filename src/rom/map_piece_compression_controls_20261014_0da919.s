.setcpu "65816"
.segment "CODE"
.org $A919
map_control_0da919:
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
