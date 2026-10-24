.setcpu "65816"
.segment "CODE"
.org $0075
map_control_0f0075:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
