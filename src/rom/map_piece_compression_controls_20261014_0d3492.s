.setcpu "65816"
.segment "CODE"
.org $3492
map_control_0d3492:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
