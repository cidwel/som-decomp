.setcpu "65816"
.segment "CODE"
.org $D385
map_control_0fd385:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
