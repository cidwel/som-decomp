.setcpu "65816"
.segment "CODE"
.org $4790
map_control_0c4790:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
