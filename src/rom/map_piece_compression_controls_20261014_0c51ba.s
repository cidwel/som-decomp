.setcpu "65816"
.segment "CODE"
.org $51BA
map_control_0c51ba:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
