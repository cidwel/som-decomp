.setcpu "65816"
.segment "CODE"
.org $0C9E
map_control_0e0c9e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
