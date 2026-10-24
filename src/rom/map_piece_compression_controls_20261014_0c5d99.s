.setcpu "65816"
.segment "CODE"
.org $5D99
map_control_0c5d99:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
