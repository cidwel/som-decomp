.setcpu "65816"
.segment "CODE"
.org $3219
map_control_0e3219:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
