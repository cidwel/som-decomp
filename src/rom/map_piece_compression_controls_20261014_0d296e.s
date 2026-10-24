.setcpu "65816"
.segment "CODE"
.org $296E
map_control_0d296e:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
