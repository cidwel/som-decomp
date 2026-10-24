.setcpu "65816"
.segment "CODE"
.org $85A5
map_control_0e85a5:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
