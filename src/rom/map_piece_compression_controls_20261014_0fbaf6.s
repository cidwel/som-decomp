.setcpu "65816"
.segment "CODE"
.org $BAF6
map_control_0fbaf6:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
