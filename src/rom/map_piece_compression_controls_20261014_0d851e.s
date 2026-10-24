.setcpu "65816"
.segment "CODE"
.org $851E
map_control_0d851e:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
