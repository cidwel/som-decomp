.setcpu "65816"
.segment "CODE"
.org $87E3
map_control_0e87e3:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
