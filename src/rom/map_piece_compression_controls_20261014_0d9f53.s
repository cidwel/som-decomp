.setcpu "65816"
.segment "CODE"
.org $9F53
map_control_0d9f53:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
