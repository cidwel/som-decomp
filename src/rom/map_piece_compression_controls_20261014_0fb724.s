.setcpu "65816"
.segment "CODE"
.org $B724
map_control_0fb724:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
