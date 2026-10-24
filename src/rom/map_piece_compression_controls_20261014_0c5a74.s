.setcpu "65816"
.segment "CODE"
.org $5A74
map_control_0c5a74:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
