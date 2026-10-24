.setcpu "65816"
.segment "CODE"
.org $029B
map_control_0f029b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
