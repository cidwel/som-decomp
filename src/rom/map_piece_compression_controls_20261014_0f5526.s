.setcpu "65816"
.segment "CODE"
.org $5526
map_control_0f5526:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C5 ; same-value copy count/distance
