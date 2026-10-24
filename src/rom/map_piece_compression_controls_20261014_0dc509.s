.setcpu "65816"
.segment "CODE"
.org $C509
map_control_0dc509:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
