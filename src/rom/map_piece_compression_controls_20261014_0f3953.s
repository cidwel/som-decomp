.setcpu "65816"
.segment "CODE"
.org $3953
map_control_0f3953:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
