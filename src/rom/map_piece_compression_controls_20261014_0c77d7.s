.setcpu "65816"
.segment "CODE"
.org $77D7
map_control_0c77d7:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
