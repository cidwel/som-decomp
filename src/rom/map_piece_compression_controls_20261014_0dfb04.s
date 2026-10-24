.setcpu "65816"
.segment "CODE"
.org $FB04
map_control_0dfb04:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
