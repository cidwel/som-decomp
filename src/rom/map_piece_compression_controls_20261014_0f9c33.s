.setcpu "65816"
.segment "CODE"
.org $9C33
map_control_0f9c33:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
