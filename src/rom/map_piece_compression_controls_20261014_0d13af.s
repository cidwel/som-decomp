.setcpu "65816"
.segment "CODE"
.org $13AF
map_control_0d13af:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
