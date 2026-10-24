.setcpu "65816"
.segment "CODE"
.org $7A91
map_control_0d7a91:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
