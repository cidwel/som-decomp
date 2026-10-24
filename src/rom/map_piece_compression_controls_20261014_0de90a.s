.setcpu "65816"
.segment "CODE"
.org $E90A
map_control_0de90a:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
