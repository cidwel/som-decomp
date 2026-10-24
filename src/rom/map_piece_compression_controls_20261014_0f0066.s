.setcpu "65816"
.segment "CODE"
.org $0066
map_control_0f0066:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
