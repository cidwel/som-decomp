.setcpu "65816"
.segment "CODE"
.org $C18C
map_control_0dc18c:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
