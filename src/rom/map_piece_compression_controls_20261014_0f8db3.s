.setcpu "65816"
.segment "CODE"
.org $8DB3
map_control_0f8db3:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
