.setcpu "65816"
.segment "CODE"
.org $3F48
map_control_0e3f48:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
