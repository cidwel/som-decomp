.setcpu "65816"
.segment "CODE"
.org $58DB
map_control_0d58db:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
