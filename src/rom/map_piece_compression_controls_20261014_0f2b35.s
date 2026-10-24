.setcpu "65816"
.segment "CODE"
.org $2B35
map_control_0f2b35:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
