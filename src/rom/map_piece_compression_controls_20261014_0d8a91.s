.setcpu "65816"
.segment "CODE"
.org $8A91
map_control_0d8a91:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
