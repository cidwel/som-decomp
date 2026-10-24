.setcpu "65816"
.segment "CODE"
.org $50D7
map_control_0c50d7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
