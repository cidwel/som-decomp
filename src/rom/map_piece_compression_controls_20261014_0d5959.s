.setcpu "65816"
.segment "CODE"
.org $5959
map_control_0d5959:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
