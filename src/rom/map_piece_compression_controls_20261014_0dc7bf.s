.setcpu "65816"
.segment "CODE"
.org $C7BF
map_control_0dc7bf:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
