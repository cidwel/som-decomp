.setcpu "65816"
.segment "CODE"
.org $5437
map_control_0d5437:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
