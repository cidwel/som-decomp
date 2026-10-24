.setcpu "65816"
.segment "CODE"
.org $118C
map_control_0e118c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
