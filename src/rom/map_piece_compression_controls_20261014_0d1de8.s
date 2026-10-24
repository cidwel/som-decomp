.setcpu "65816"
.segment "CODE"
.org $1DE8
map_control_0d1de8:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
