.setcpu "65816"
.segment "CODE"
.org $E295
map_control_0de295:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
