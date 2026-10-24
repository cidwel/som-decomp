.setcpu "65816"
.segment "CODE"
.org $2675
map_control_0f2675:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
