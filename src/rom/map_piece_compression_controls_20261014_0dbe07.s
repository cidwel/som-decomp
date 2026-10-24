.setcpu "65816"
.segment "CODE"
.org $BE07
map_control_0dbe07:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
