.setcpu "65816"
.segment "CODE"
.org $FB0D
map_control_0ffb0d:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
