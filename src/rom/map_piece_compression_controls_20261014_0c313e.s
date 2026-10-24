.setcpu "65816"
.segment "CODE"
.org $313E
map_control_0c313e:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
