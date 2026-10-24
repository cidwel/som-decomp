.setcpu "65816"
.segment "CODE"
.org $5A8E
map_control_0d5a8e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
