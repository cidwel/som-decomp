.setcpu "65816"
.segment "CODE"
.org $D790
map_control_0ed790:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
