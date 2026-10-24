.setcpu "65816"
.segment "CODE"
.org $B043
map_control_0eb043:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
