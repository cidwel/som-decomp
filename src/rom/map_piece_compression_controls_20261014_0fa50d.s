.setcpu "65816"
.segment "CODE"
.org $A50D
map_control_0fa50d:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
