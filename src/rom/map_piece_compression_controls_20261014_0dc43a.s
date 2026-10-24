.setcpu "65816"
.segment "CODE"
.org $C43A
map_control_0dc43a:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
