.setcpu "65816"
.segment "CODE"
.org $8BD5
map_control_0e8bd5:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
