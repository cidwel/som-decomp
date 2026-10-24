.setcpu "65816"
.segment "CODE"
.org $9E4A
map_control_0d9e4a:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
