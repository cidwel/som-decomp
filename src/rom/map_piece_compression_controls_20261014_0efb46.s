.setcpu "65816"
.segment "CODE"
.org $FB46
map_control_0efb46:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
