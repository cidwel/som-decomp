.setcpu "65816"
.segment "CODE"
.org $92C3
map_control_0c92c3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
