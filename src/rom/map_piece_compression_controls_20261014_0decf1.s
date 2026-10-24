.setcpu "65816"
.segment "CODE"
.org $ECF1
map_control_0decf1:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
