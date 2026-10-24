.setcpu "65816"
.segment "CODE"
.org $AD72
map_control_0ead72:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
