.setcpu "65816"
.segment "CODE"
.org $5628
map_control_0d5628:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
