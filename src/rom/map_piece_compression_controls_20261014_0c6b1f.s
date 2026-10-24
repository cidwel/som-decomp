.setcpu "65816"
.segment "CODE"
.org $6B1F
map_control_0c6b1f:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
