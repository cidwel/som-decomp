.setcpu "65816"
.segment "CODE"
.org $E7FC
map_control_0fe7fc:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
