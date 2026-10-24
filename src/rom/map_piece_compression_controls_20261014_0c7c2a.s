.setcpu "65816"
.segment "CODE"
.org $7C2A
map_control_0c7c2a:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
