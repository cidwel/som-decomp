.setcpu "65816"
.segment "CODE"
.org $70B7
map_control_0f70b7:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
