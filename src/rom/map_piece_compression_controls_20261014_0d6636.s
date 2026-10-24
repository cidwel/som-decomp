.setcpu "65816"
.segment "CODE"
.org $6636
map_control_0d6636:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
