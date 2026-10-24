.setcpu "65816"
.segment "CODE"
.org $FB5A
map_control_0efb5a:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
