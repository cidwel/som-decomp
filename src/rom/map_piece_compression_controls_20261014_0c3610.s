.setcpu "65816"
.segment "CODE"
.org $3610
map_control_0c3610:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
