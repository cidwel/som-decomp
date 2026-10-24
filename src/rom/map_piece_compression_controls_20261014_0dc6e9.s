.setcpu "65816"
.segment "CODE"
.org $C6E9
map_control_0dc6e9:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
