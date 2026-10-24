.setcpu "65816"
.segment "CODE"
.org $9038
map_control_0c9038:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
