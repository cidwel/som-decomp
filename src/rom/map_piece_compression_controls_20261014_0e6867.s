.setcpu "65816"
.segment "CODE"
.org $6867
map_control_0e6867:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
