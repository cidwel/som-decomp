.setcpu "65816"
.segment "CODE"
.org $7858
map_control_0d7858:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
