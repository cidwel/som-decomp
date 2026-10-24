.setcpu "65816"
.segment "CODE"
.org $2B8C
map_control_0f2b8c:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
