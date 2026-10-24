.setcpu "65816"
.segment "CODE"
.org $7FA4
map_control_0c7fa4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
