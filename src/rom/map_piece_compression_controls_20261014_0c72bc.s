.setcpu "65816"
.segment "CODE"
.org $72BC
map_control_0c72bc:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
