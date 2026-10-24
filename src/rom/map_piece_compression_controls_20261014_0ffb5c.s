.setcpu "65816"
.segment "CODE"
.org $FB5C
map_control_0ffb5c:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
