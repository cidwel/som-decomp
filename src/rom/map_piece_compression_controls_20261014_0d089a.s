.setcpu "65816"
.segment "CODE"
.org $089A
map_control_0d089a:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
