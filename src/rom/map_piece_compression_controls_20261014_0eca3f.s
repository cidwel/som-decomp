.setcpu "65816"
.segment "CODE"
.org $CA3F
map_control_0eca3f:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
