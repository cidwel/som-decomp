.setcpu "65816"
.segment "CODE"
.org $25C2
map_control_0d25c2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
