.setcpu "65816"
.segment "CODE"
.org $75FC
map_control_0c75fc:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
