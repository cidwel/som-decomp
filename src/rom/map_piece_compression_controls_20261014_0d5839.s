.setcpu "65816"
.segment "CODE"
.org $5839
map_control_0d5839:
    .byte $EB ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
