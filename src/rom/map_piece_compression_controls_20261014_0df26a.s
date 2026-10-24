.setcpu "65816"
.segment "CODE"
.org $F26A
map_control_0df26a:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
