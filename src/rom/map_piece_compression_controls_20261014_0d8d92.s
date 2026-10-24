.setcpu "65816"
.segment "CODE"
.org $8D92
map_control_0d8d92:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
