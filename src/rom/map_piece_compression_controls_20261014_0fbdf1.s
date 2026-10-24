.setcpu "65816"
.segment "CODE"
.org $BDF1
map_control_0fbdf1:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
