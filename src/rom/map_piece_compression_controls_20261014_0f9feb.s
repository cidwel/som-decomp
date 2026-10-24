.setcpu "65816"
.segment "CODE"
.org $9FEB
map_control_0f9feb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
