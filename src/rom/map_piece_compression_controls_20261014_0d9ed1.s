.setcpu "65816"
.segment "CODE"
.org $9ED1
map_control_0d9ed1:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
