.setcpu "65816"
.segment "CODE"
.org $5390
map_control_0e5390:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
