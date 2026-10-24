.setcpu "65816"
.segment "CODE"
.org $13EE
map_control_0e13ee:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
