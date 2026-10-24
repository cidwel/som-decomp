.setcpu "65816"
.segment "CODE"
.org $ECFD
map_control_0decfd:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
