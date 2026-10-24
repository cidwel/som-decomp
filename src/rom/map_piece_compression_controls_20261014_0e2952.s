.setcpu "65816"
.segment "CODE"
.org $2952
map_control_0e2952:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
