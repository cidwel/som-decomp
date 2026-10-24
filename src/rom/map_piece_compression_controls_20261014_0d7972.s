.setcpu "65816"
.segment "CODE"
.org $7972
map_control_0d7972:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
