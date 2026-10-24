.setcpu "65816"
.segment "CODE"
.org $858D
map_control_0d858d:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
