.setcpu "65816"
.segment "CODE"
.org $E9F3
map_control_0de9f3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
