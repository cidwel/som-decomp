.setcpu "65816"
.segment "CODE"
.org $EB7A
map_control_0deb7a:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
