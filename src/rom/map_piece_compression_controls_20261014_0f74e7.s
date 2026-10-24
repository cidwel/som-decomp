.setcpu "65816"
.segment "CODE"
.org $74E7
map_control_0f74e7:
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
