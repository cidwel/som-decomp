.setcpu "65816"
.segment "CODE"
.org $D9CE
map_control_0ed9ce:
    .byte $D9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $CE ; same-value copy count/distance
