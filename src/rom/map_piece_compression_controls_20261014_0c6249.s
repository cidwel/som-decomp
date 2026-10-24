.setcpu "65816"
.segment "CODE"
.org $6249
map_control_0c6249:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
