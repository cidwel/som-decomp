.setcpu "65816"
.segment "CODE"
.org $E388
map_control_0de388:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
