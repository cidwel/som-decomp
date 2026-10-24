.setcpu "65816"
.segment "CODE"
.org $EBF3
map_control_0debf3:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
