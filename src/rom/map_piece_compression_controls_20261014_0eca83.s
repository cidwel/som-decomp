.setcpu "65816"
.segment "CODE"
.org $CA83
map_control_0eca83:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
