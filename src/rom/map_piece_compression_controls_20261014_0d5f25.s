.setcpu "65816"
.segment "CODE"
.org $5F25
map_control_0d5f25:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
