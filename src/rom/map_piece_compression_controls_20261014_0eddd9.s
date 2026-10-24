.setcpu "65816"
.segment "CODE"
.org $DDD9
map_control_0eddd9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
