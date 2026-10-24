.setcpu "65816"
.segment "CODE"
.org $2AD0
map_control_0f2ad0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
