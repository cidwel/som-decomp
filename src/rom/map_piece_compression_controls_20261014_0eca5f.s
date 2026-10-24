.setcpu "65816"
.segment "CODE"
.org $CA5F
map_control_0eca5f:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
