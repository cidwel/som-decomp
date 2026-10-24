.setcpu "65816"
.segment "CODE"
.org $FB7E
map_control_0efb7e:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
