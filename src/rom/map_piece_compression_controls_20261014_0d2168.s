.setcpu "65816"
.segment "CODE"
.org $2168
map_control_0d2168:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
