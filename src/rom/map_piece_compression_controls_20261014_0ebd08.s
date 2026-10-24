.setcpu "65816"
.segment "CODE"
.org $BD08
map_control_0ebd08:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
