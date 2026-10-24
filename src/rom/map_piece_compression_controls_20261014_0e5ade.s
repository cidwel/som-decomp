.setcpu "65816"
.segment "CODE"
.org $5ADE
map_control_0e5ade:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
