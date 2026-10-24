.setcpu "65816"
.segment "CODE"
.org $672E
map_control_0f672e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
