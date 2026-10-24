.setcpu "65816"
.segment "CODE"
.org $59E4
map_control_0d59e4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
