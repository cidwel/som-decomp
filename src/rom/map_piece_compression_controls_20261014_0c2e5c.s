.setcpu "65816"
.segment "CODE"
.org $2E5C
map_control_0c2e5c:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
