.setcpu "65816"
.segment "CODE"
.org $B85B
map_control_0fb85b:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
