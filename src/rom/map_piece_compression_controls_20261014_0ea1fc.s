.setcpu "65816"
.segment "CODE"
.org $A1FC
map_control_0ea1fc:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E7 ; previous-row copy count
