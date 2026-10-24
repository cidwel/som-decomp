.setcpu "65816"
.segment "CODE"
.org $F264
map_control_0df264:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
