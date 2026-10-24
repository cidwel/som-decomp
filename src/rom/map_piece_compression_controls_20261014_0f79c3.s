.setcpu "65816"
.segment "CODE"
.org $79C3
map_control_0f79c3:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
