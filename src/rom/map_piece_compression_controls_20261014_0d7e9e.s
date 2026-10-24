.setcpu "65816"
.segment "CODE"
.org $7E9E
map_control_0d7e9e:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
