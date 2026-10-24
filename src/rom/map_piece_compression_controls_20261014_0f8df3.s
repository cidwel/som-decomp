.setcpu "65816"
.segment "CODE"
.org $8DF3
map_control_0f8df3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
