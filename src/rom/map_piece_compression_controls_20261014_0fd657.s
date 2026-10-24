.setcpu "65816"
.segment "CODE"
.org $D657
map_control_0fd657:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
