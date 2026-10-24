.setcpu "65816"
.segment "CODE"
.org $A8E5
map_control_0ea8e5:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
