.setcpu "65816"
.segment "CODE"
.org $CA3E
map_control_0fca3e:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
