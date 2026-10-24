.setcpu "65816"
.segment "CODE"
.org $67DC
map_control_0d67dc:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
