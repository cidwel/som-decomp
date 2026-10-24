.setcpu "65816"
.segment "CODE"
.org $678C
map_control_0c678c:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
