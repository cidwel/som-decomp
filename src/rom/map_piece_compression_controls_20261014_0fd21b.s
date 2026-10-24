.setcpu "65816"
.segment "CODE"
.org $D21B
map_control_0fd21b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
