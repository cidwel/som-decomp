.setcpu "65816"
.segment "CODE"
.org $5523
map_control_0f5523:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
