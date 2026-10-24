.setcpu "65816"
.segment "CODE"
.org $B4AD
map_control_0db4ad:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
