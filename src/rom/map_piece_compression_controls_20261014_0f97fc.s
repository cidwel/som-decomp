.setcpu "65816"
.segment "CODE"
.org $97FC
map_control_0f97fc:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
