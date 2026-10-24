.setcpu "65816"
.segment "CODE"
.org $A72D
map_control_0da72d:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
