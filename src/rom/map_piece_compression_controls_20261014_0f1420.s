.setcpu "65816"
.segment "CODE"
.org $1420
map_control_0f1420:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
