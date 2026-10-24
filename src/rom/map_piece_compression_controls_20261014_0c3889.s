.setcpu "65816"
.segment "CODE"
.org $3889
map_control_0c3889:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
