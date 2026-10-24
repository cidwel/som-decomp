.setcpu "65816"
.segment "CODE"
.org $57E8
map_control_0d57e8:
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
