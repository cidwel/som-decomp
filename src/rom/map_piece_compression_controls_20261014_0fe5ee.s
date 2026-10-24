.setcpu "65816"
.segment "CODE"
.org $E5EE
map_control_0fe5ee:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
