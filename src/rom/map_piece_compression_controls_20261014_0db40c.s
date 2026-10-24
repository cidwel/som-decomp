.setcpu "65816"
.segment "CODE"
.org $B40C
map_control_0db40c:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
