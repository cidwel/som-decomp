.setcpu "65816"
.segment "CODE"
.org $6BAF
map_control_0c6baf:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
