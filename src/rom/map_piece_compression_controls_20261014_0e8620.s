.setcpu "65816"
.segment "CODE"
.org $8620
map_control_0e8620:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
