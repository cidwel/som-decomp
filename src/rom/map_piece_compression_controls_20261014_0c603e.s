.setcpu "65816"
.segment "CODE"
.org $603E
map_control_0c603e:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
