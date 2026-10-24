.setcpu "65816"
.segment "CODE"
.org $DDD3
map_control_0dddd3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
