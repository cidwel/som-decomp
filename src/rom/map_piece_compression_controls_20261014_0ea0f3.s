.setcpu "65816"
.segment "CODE"
.org $A0F3
map_control_0ea0f3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
