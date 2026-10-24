.setcpu "65816"
.segment "CODE"
.org $1397
map_control_0d1397:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
