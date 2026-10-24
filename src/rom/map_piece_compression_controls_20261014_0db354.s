.setcpu "65816"
.segment "CODE"
.org $B354
map_control_0db354:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
