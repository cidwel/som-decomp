.setcpu "65816"
.segment "CODE"
.org $C007
map_control_0dc007:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
