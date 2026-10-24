.setcpu "65816"
.segment "CODE"
.org $5E8E
map_control_0d5e8e:
    .byte $E4 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
