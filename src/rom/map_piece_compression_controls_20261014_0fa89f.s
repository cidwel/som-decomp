.setcpu "65816"
.segment "CODE"
.org $A89F
map_control_0fa89f:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
