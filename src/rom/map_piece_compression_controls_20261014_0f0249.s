.setcpu "65816"
.segment "CODE"
.org $0249
map_control_0f0249:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
