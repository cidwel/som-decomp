.setcpu "65816"
.segment "CODE"
.org $1780
map_control_0e1780:
    .byte $CE ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
