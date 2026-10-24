.setcpu "65816"
.segment "CODE"
.org $2E85
map_control_0c2e85:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
