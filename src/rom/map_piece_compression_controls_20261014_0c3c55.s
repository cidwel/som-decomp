.setcpu "65816"
.segment "CODE"
.org $3C55
map_control_0c3c55:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
