.setcpu "65816"
.segment "CODE"
.org $736C
map_control_0c736c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
