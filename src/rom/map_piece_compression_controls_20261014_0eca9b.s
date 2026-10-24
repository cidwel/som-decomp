.setcpu "65816"
.segment "CODE"
.org $CA9B
map_control_0eca9b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
