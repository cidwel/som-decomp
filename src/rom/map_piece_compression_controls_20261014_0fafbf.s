.setcpu "65816"
.segment "CODE"
.org $AFBF
map_control_0fafbf:
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
