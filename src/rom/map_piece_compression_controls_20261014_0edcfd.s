.setcpu "65816"
.segment "CODE"
.org $DCFD
map_control_0edcfd:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
