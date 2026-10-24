.setcpu "65816"
.segment "CODE"
.org $D959
map_control_0fd959:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
