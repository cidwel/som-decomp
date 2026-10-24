.setcpu "65816"
.segment "CODE"
.org $5CEE
map_control_0f5cee:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
