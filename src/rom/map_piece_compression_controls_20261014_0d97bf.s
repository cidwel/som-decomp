.setcpu "65816"
.segment "CODE"
.org $97BF
map_control_0d97bf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
