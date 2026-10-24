.setcpu "65816"
.segment "CODE"
.org $EB82
map_control_0deb82:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
