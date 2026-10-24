.setcpu "65816"
.segment "CODE"
.org $A1F8
map_control_0ea1f8:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E7 ; previous-row copy count
