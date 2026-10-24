.setcpu "65816"
.segment "CODE"
.org $C621
map_control_0dc621:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
