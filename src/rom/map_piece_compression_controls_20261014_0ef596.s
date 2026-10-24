.setcpu "65816"
.segment "CODE"
.org $F596
map_control_0ef596:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
