.setcpu "65816"
.segment "CODE"
.org $CA54
map_control_0eca54:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
