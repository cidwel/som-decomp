.setcpu "65816"
.segment "CODE"
.org $97EE
map_control_0e97ee:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
