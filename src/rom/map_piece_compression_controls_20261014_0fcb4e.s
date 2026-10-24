.setcpu "65816"
.segment "CODE"
.org $CB4E
map_control_0fcb4e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
