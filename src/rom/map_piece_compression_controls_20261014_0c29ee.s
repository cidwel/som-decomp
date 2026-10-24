.setcpu "65816"
.segment "CODE"
.org $29EE
map_control_0c29ee:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
