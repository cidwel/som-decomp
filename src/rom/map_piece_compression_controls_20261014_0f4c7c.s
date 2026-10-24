.setcpu "65816"
.segment "CODE"
.org $4C7C
map_control_0f4c7c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
