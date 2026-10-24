.setcpu "65816"
.segment "CODE"
.org $FB71
map_control_0dfb71:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
