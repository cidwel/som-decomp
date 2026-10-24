.setcpu "65816"
.segment "CODE"
.org $FBCA
map_control_0efbca:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
