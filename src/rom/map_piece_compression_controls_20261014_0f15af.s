.setcpu "65816"
.segment "CODE"
.org $15AF
map_control_0f15af:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
