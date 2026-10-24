.setcpu "65816"
.segment "CODE"
.org $9FFA
map_control_0e9ffa:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
