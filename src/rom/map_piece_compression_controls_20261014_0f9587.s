.setcpu "65816"
.segment "CODE"
.org $9587
map_control_0f9587:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6B ; distance low bit/count
