.setcpu "65816"
.segment "CODE"
.org $7058
map_control_0f7058:
    .byte $E2 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E3 ; previous-row copy count
