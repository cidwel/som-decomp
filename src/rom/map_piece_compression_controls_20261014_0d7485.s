.setcpu "65816"
.segment "CODE"
.org $7485
map_control_0d7485:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
