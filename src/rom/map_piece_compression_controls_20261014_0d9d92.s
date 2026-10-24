.setcpu "65816"
.segment "CODE"
.org $9D92
map_control_0d9d92:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
