.setcpu "65816"
.segment "CODE"
.org $1C5F
map_control_0e1c5f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
