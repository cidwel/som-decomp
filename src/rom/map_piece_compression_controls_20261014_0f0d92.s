.setcpu "65816"
.segment "CODE"
.org $0D92
map_control_0f0d92:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
