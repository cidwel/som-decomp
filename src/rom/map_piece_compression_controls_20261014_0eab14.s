.setcpu "65816"
.segment "CODE"
.org $AB14
map_control_0eab14:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
