.setcpu "65816"
.segment "CODE"
.org $59F8
map_control_0d59f8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
