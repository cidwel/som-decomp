.setcpu "65816"
.segment "CODE"
.org $841A
map_control_0e841a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
