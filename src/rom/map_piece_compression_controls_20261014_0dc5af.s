.setcpu "65816"
.segment "CODE"
.org $C5AF
map_control_0dc5af:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
