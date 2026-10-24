.setcpu "65816"
.segment "CODE"
.org $D605
map_control_0fd605:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
