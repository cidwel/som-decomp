.setcpu "65816"
.segment "CODE"
.org $4759
map_control_0f4759:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
