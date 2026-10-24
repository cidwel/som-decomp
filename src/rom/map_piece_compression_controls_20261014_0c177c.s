.setcpu "65816"
.segment "CODE"
.org $177C
map_control_0c177c:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
