.setcpu "65816"
.segment "CODE"
.org $F5B2
map_control_0cf5b2:
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
    .byte $E1 ; previous-row copy count
