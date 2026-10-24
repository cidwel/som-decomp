.setcpu "65816"
.segment "CODE"
.org $57BD
map_control_0d57bd:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $DA ; same-value copy count/distance
