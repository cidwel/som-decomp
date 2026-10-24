.setcpu "65816"
.segment "CODE"
.org $9D93
map_control_0f9d93:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
