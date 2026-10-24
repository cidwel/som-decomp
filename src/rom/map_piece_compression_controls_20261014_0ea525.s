.setcpu "65816"
.segment "CODE"
.org $A525
map_control_0ea525:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
