.setcpu "65816"
.segment "CODE"
.org $5FE7
map_control_0f5fe7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
