.setcpu "65816"
.segment "CODE"
.org $155B
map_control_0d155b:
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
