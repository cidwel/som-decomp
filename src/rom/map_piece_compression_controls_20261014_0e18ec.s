.setcpu "65816"
.segment "CODE"
.org $18EC
map_control_0e18ec:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
