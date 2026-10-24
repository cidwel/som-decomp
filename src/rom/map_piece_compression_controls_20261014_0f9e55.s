.setcpu "65816"
.segment "CODE"
.org $9E55
map_control_0f9e55:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
