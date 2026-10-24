.setcpu "65816"
.segment "CODE"
.org $A35A
map_control_0fa35a:
    .byte $E0 ; previous-row copy escape
    .byte $7A ; row-distance/count
