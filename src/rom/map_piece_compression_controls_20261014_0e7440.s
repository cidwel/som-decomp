.setcpu "65816"
.segment "CODE"
.org $7440
map_control_0e7440:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
