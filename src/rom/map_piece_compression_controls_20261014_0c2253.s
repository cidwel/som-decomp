.setcpu "65816"
.segment "CODE"
.org $2253
map_control_0c2253:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
