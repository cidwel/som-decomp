.setcpu "65816"
.segment "CODE"
.org $7760
map_control_0f7760:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
