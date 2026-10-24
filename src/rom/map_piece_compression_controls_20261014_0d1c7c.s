.setcpu "65816"
.segment "CODE"
.org $1C7C
map_control_0d1c7c:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
