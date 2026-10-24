.setcpu "65816"
.segment "CODE"
.org $3F8D
map_control_0d3f8d:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
