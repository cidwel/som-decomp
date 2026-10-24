.setcpu "65816"
.segment "CODE"
.org $3FA0
map_control_0e3fa0:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
