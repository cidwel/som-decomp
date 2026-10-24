.setcpu "65816"
.segment "CODE"
.org $63F0
map_control_0c63f0:
    .byte $CE ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $49 ; row-distance/count
