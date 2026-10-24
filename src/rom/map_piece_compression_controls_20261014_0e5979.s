.setcpu "65816"
.segment "CODE"
.org $5979
map_control_0e5979:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
