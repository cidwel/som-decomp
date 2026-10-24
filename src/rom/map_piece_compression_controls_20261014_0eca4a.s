.setcpu "65816"
.segment "CODE"
.org $CA4A
map_control_0eca4a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
