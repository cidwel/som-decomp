.setcpu "65816"
.segment "CODE"
.org $5122
map_control_0f5122:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
