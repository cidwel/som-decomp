.setcpu "65816"
.segment "CODE"
.org $97BF
map_control_0e97bf:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
