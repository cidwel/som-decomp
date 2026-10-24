.setcpu "65816"
.segment "CODE"
.org $DDF1
map_control_0fddf1:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
