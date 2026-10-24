.setcpu "65816"
.segment "CODE"
.org $C4FC
map_control_0dc4fc:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
