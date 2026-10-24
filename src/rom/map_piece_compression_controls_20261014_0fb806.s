.setcpu "65816"
.segment "CODE"
.org $B806
map_control_0fb806:
    .byte $E0 ; previous-row copy escape
    .byte $5D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
