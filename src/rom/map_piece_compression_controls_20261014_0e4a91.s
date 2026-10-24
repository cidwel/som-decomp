.setcpu "65816"
.segment "CODE"
.org $4A91
map_control_0e4a91:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
