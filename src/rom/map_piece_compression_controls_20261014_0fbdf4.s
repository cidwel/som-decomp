.setcpu "65816"
.segment "CODE"
.org $BDF4
map_control_0fbdf4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
