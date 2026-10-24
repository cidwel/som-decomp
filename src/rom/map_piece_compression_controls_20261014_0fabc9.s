.setcpu "65816"
.segment "CODE"
.org $ABC9
map_control_0fabc9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
