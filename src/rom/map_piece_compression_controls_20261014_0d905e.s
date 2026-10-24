.setcpu "65816"
.segment "CODE"
.org $905E
map_control_0d905e:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
