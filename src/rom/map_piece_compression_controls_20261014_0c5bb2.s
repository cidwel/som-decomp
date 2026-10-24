.setcpu "65816"
.segment "CODE"
.org $5BB2
map_control_0c5bb2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
