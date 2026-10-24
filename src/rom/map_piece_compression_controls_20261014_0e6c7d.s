.setcpu "65816"
.segment "CODE"
.org $6C7D
map_control_0e6c7d:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
