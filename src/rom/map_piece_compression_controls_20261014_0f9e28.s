.setcpu "65816"
.segment "CODE"
.org $9E28
map_control_0f9e28:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
