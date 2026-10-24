.setcpu "65816"
.segment "CODE"
.org $C7FC
map_control_0fc7fc:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
