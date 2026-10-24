.setcpu "65816"
.segment "CODE"
.org $F5C4
map_control_0cf5c4:
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
    .byte $E1 ; previous-row copy count
