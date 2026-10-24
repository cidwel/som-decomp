.setcpu "65816"
.segment "CODE"
.org $5637
map_control_0d5637:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
