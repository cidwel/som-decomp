.setcpu "65816"
.segment "CODE"
.org $2732
map_control_0c2732:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
