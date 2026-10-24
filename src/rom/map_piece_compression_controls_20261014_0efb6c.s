.setcpu "65816"
.segment "CODE"
.org $FB6C
map_control_0efb6c:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
