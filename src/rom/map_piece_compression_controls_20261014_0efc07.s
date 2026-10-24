.setcpu "65816"
.segment "CODE"
.org $FC07
map_control_0efc07:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
