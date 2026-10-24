.setcpu "65816"
.segment "CODE"
.org $9B10
map_control_0e9b10:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
