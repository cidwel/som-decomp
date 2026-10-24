.setcpu "65816"
.segment "CODE"
.org $3C2B
map_control_0d3c2b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
