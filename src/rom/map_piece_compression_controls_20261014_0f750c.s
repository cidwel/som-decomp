.setcpu "65816"
.segment "CODE"
.org $750C
map_control_0f750c:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
