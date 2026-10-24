.setcpu "65816"
.segment "CODE"
.org $C2F0
map_control_0dc2f0:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
