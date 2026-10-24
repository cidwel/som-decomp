.setcpu "65816"
.segment "CODE"
.org $40BF
map_control_0c40bf:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
