.setcpu "65816"
.segment "CODE"
.org $A1F4
map_control_0ea1f4:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E6 ; previous-row copy count
