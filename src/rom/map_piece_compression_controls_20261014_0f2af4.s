.setcpu "65816"
.segment "CODE"
.org $2AF4
map_control_0f2af4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
