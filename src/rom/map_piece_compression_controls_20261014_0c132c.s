.setcpu "65816"
.segment "CODE"
.org $132C
map_control_0c132c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
