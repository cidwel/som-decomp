.setcpu "65816"
.segment "CODE"
.org $C895
map_control_0ec895:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E6 ; previous-row copy count
