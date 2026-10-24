.setcpu "65816"
.segment "CODE"
.org $8279
map_control_0e8279:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
