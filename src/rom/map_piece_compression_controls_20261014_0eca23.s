.setcpu "65816"
.segment "CODE"
.org $CA23
map_control_0eca23:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
